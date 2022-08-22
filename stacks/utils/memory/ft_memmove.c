/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:55:25 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/21 21:16:52 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

/*
 *	'is_before' know if the adresse of 'dest' preced the adresse of 'src'
 *	his value is either 0 or 1. It used by 'direction' and 'index' to define
 *	how to travel the data.
 *
 *	'direction' meant to be used to travel forward or backward
 *	his value is either -1 or 1.
 *
 *	'index' used to be the index where we start travelling the data
 *	his value is either 0 or (n - 1).
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		is_before;
	int		direction;
	size_t	index;

	if (!dest || !src)
		return (dest);
	is_before = (dest < src);
	direction = is_before -(!is_before);
	index = (n - !is_before) * (!is_before);
	while (n--)
	{
		((char *)dest)[index] = ((char *)src)[index];
		index += direction;
	}
	return (dest);
}
