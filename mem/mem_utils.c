/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:31:32 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/15 17:14:55 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_utils.h"

t_data	ft_memset(t_data ptr, int c, size_t n)
{
	while (ptr.data && n--)
		((char *)ptr.data)[n] = c;
	return (ptr);
}

t_data	ft_calloc(t_mem_size size)
{
	size_t	n;

	if (!mem_size_check(size))
		return ((t_data){NULL});
	n = mem_size_total(size);
	return (ft_memset(malloc(n), 0, n));
}

bool	calloc_to(t_data output, t_mem_size size)
{
	*(output.ptr) = ft_calloc(size).data;
	return (*output.ptr);
}
