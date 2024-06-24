/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyte <hbyte@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 08:14:03 by hamalmar          #+#    #+#             */
/*   Updated: 2024/05/13 22:37:18 by hbyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_address(void *arg)
{
	int					count;
	int					i;
	unsigned long long	num;
	char				address[17];

	count = 0;
	if (!arg)
		return (write(1, "0x0", 3));
	num = (unsigned long long)arg;
	count += write(1, "0x", 2);
	i = 0;
	while (num)
	{
		address[i++] = LOWER[num % 16];
		num /= 16;
	}
	address[i] = '\0';
	while (i > 0)
	{
		i--;
		count += write(1, &address[i], 1);
	}
	return (count);
}
