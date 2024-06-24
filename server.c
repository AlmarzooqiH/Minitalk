/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hbyte <hbyte@student.42.fr>                +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/01 15:55:49 by hbyte             #+#    #+#             */
/*   Updated: 2024/03/01 15:55:49 by hbyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
		src: https://www.asciiart.eu/text-to-ascii-art
				 __  __ ___ _   _ ___ _____  _    _     _  __
				|  \/  |_ _| \ | |_ _|_   _|/ \  | |   | |/ /
				| |\/| || ||  \| || |  | | / _ \ | |   | ' / 
				| |  | || || |\  || |  | |/ ___ \| |___| . \ 
				|_|  |_|___|_| \_|___| |_/_/   \_\_____|_|\_\
				__  _     _    _  _____ ___ _   _ ___ __  __ 
				\ \| |   | |  / \|_   _|_ _| | / |_ _|  \/  |
				 \ ` |   | | / _ \ | |  | || |/  || || |\/| |
				 / . |___| |/ ___ \| |  | ||  /| || || |  | |
				/_/|_|_____/_/   \_|_| |___|_/ |_|___|_|  |_|
*/

#include "minitalk.h"

// Binary to Integer
int	btoi(int currentBP, int signal_num)
{
	if (currentBP < 0 || signal_num == SIGUSR1)
		return (0);
	if (currentBP == 0 && signal_num == SIGUSR2)
		return (1);
	return (2 * btoi(--currentBP, SIGUSR2));
}

//Will recive the message character by character, bit by bit.
void	recieve_message(char *message, int signal_num, int *message_size)
{
	static int	current_bit;
	static int	flag;

	if (current_bit == 0 && flag == 0)
	{
		current_bit = 7;
		flag++;
	}
	if (current_bit >= 0 && (signal_num == SIGUSR1 || signal_num == SIGUSR2))
	{
		message[*message_size] += btoi(current_bit, signal_num);
		current_bit--;
		if (current_bit < 0)
		{
			*message_size = *message_size - 1;
			current_bit = 7;
		}
	}
	if (*message_size < 0)
	{
		current_bit = 0;
		flag = 0;
	}
}

/*	
	Will print the recived message and then
	reset the variables so we can reicve more messages.
*/
void	print_and_reset(char **message, int **message_size)
{
	ft_printf("Recvied Message: %s\n", *message);
	free(*message);
	free(*message_size);
	*message = NULL;
	*message_size = NULL;
}

void	user_message(int signal_num)
{
	static int	size_bp;
	static int	*message_size;
	static char	*message;

	if (!message_size)
	{
		message_size = (int *)malloc(sizeof(int));
		if (!message_size)
			exit(EXIT_FAILURE);
		size_bp = 31;
	}
	if (size_bp >= 0 && (signal_num == SIGUSR1 || signal_num == SIGUSR2))
		*message_size += btoi(size_bp--, signal_num);
	if (message != NULL && (*message_size >= 0 || *message_size < 0))
		recieve_message(message, signal_num, message_size);
	if (size_bp == -1 && !message)
	{
		message = (char *)malloc(sizeof(char) * ((*message_size)));
		if (!message)
			exit(EXIT_FAILURE);
		message[*message_size] = '\0';
		*message_size = *message_size - 1;
	}
	if (message != NULL && *message_size < 0)
		print_and_reset(&message, &message_size);
}

int	main(void)
{
	signal(SIGUSR1, user_message);
	signal(SIGUSR2, user_message);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
