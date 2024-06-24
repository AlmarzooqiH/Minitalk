/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyte <hbyte@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:08:05 by hamalmar          #+#    #+#             */
/*   Updated: 2024/05/13 22:37:15 by hbyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	if (!str)
		return (write(1, "(null)", ft_strlen("(null)")));
	return (write(1, str, ft_strlen(str)));
}
