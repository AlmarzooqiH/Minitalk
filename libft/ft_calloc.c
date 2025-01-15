/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:59:06 by hamalmar          #+#    #+#             */
/*   Updated: 2023/11/18 18:01:42 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*intialize;

	intialize = malloc(count * size);
	if (intialize == NULL)
		return (NULL);
	ft_bzero(intialize, size * count);
	return (intialize);
}
