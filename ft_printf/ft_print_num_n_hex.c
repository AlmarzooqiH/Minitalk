/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_n_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyte <hbyte@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:07:18 by hamalmar          #+#    #+#             */
/*   Updated: 2024/05/13 22:37:17 by hbyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num_n_hex(unsigned int n, char casing)
{
	int	count;

	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else if (casing == 'x')
	{
		if (n / 16 == 0)
			return (write(1, &LOWER[n % 16], 1));
		count += (ft_print_num_n_hex((n / 16), 'x') + write(1, &LOWER[n % 16],
					1));
	}
	else if (casing == 'X')
	{
		if (n / 16 == 0)
			return (write(1, &UPPER[n % 16], 1));
		count += (ft_print_num_n_hex((n / 16), 'X') + write(1, &UPPER[n % 16],
					1));
	}
	return (count);
}
