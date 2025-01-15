/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/06/30 11:16:12 by hamalmar          #+#    #+#             */
/*   Updated: 2024/06/30 11:16:12 by hamalmar         ###   ########.fr       */
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
int	btoi(int current_bp, int signal_num)
{
	if (current_bp < 0 || signal_num == SIGUSR1)
		return (0);
	if (current_bp == 0 && signal_num == SIGUSR2)
		return (1);
	return (2 * btoi(--current_bp, SIGUSR2));
}

void	recieve_message(int signal_num)
{
	static int	current_cbp;
	static int	flag;
	static char	current_c;

	if (current_cbp == 0 && flag == 0)
	{
		current_cbp = 7;
		current_c = 0;
		flag--;
	}
	if (current_cbp >= 0 && (signal_num == SIGUSR1 || signal_num == SIGUSR2))
		current_c += btoi(current_cbp--, signal_num);
	if (current_cbp == -1 && current_cbp == -1)
	{
		ft_printf("%c", current_c);
		current_cbp = 0;
		flag = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, recieve_message);
	signal(SIGUSR2, recieve_message);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
}
