/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:50:17 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/15 17:20:00 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"


inline t_const_mem	mem_new(t_mem_size size)
{
	return ((t_const_mem){HEAP, ft_calloc(size), size});
}

inline t_const_mem	mem_define(t_data data, t_mem_size size)
{
	return ((t_const_mem){STACK, data, size});
}

inline t_data	mem_get_by_index(t_mem input, t_index idx)
{
	if (idx >= input.nmemb)
		return (NULL);
	return (input.data + (input.size * idx));
}
