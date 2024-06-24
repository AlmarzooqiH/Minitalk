/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_num.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyte <hbyte@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:11:18 by hamalmar          #+#    #+#             */
/*   Updated: 2024/05/13 22:37:14 by hbyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_num(unsigned int n)
{
	char	current_digit;

	if (n <= 9)
	{
		current_digit = n + '0';
		return (write(1, &current_digit, 1));
	}
	current_digit = (n % 10) + '0';
	return (ft_print_number(n / 10) + write(1, &current_digit, 1));
}
