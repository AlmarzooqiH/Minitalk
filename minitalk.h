/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:16:49 by hamalmar          #+#    #+#             */
/*   Updated: 2024/07/03 14:17:48 by hamalmar         ###   ########.fr       */
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

#ifndef MINITALK_H
# define MINITALK_H
# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		btoi(int current_bp, int signal_num);
void	recieve_message(int signal_num);
void	send_message(int pid, const char *message, int size);
#endif