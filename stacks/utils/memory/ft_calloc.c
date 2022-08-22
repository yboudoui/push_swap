/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:04:44 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/21 21:16:15 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	n;

	n = size * nmemb;
	if (!n)
		return (malloc(0));
	if ((n / size) != nmemb)
		return (NULL);
	return (ft_memset(malloc(n), 0, n));
}
