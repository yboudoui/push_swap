/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:37:40 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/15 14:29:37 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_size.h"

inline t_mem_size	mem_size_new(size_t size_of_type, size_t number_of_member)
{
	return ((t_mem_size){size_of_type, number_of_member});
}

inline size_t	mem_size_total(t_mem_size size)
{
	return (size.size * size.nmemb);
}

static inline bool	mem_size_is_null(t_mem_size size)
{
	return (!mem_size_total(size));
}

static inline bool	mem_size_overflow(t_mem_size size)
{
	return (((mem_size_total(size) / size.size) != size.nmemb));
}

inline bool	mem_size_check(t_mem_size size)
{
	return (!mem_size_is_null(size) && !mem_size_overflow(size));
}
