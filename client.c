/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truedeveloper <truedeveloper@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:16:47 by hbyte             #+#    #+#             */
/*   Updated: 2024/06/08 13:06:39 by truedevelop      ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (sign == -1)
		num = -num;
	return (num);
}

/*
	Will run 8 times per character to send an string
	each character will b sent bit by bit.
	Via signals (SIGUSR1(0) and SIGUSR2(1))
*/
void	send_message(int pid, const char *message, int size)
{
	int		i;
	char	current_c;

	if (size < 0)
		return ;
	while (size >= 0)
	{
		current_c = message[size];
		i = 7;
		while (i >= 0)
		{
			if ((current_c >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i--;
			usleep(69);
		}
		size--;
		usleep(69);
	}
}

/*
	Will run 31 times to send an integer and send bit by bit.
	Via signals (SIGUSR1(0) and SIGUSR2(1))
*/
// itob (Integer to binary)
void	itob(int pid, int size)
{
	int	i;

	if (size < 0)
		return ;
	i = 31;
	while (i >= 0)
	{
		if ((size >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(69);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	message_size;

	pid = ft_atoi(argv[1]);
	if (!argv[2] || !pid || pid < 0)
		exit(EXIT_FAILURE);
	message_size = ft_strlen(argv[2]);
	itob(pid, message_size);
	send_message(pid, argv[2], --message_size);
	exit(EXIT_SUCCESS);
}
