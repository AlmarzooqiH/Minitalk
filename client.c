/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:14:55 by hamalmar          #+#    #+#             */
/*   Updated: 2024/07/03 14:07:08 by hamalmar         ###   ########.fr       */
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

/*
	Will run 8 times per character to send an string
	each character will b sent bit by bit.
	Via signals (SIGUSR1(0) and SIGUSR2(1))
*/

void	send_message(int pid, const char *message, int size)
{
	int		i;
	int		j;
	char	current_c;

	if (size < 0)
		return ;
	i = 0;
	while (i < size)
	{
		current_c = message[i];
		j = 7;
		while (j >= 0)
		{
			if ((current_c >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j--;
			usleep(69);
		}
		i++;
		usleep(69);
	}
}

/*
	Will run 31 times to send an integer and send bit by bit.
	Via signals (SIGUSR1(0) and SIGUSR2(1))
*/

int	main(int argc, char **argv)
{
	int	pid;
	int	message_size;

	pid = ft_atoi(argv[1]);
	if (!argv[2] || argv[2][0] == '\0' || !pid || pid < 0)
		exit(EXIT_FAILURE);
	message_size = ft_strlen(argv[2]);
	send_message(pid, argv[2], message_size);
	exit(EXIT_SUCCESS);
}
