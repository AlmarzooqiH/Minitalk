/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyte <hbyte@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:10:56 by hamalmar          #+#    #+#             */
/*   Updated: 2024/05/13 22:37:14 by hbyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define UPPER "0123456789ABCDEF"
# define LOWER "0123456789abcdef"

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
int		ft_print_str(char *str);
int		ft_print_number(int n);
int		ft_print_num_n_hex(unsigned int n, char casing);
int		ft_print_unsigned_num(unsigned int n);
int		ft_print_address(void *arg);
#endif