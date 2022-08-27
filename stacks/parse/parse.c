/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/27 12:35:41 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	ft_check_double(t_int_array *out)
{
	size_t	index_a;
	size_t	index_b;

	index_a = 0;
	while (index_a < out->len)
	{
		index_b = index_a + 1;
		while (index_b < out->len)
		{
			if (out->array[index_a] == out->array[index_b])
				return (free(out), false);
			index_b++;
		}
		index_a++;
	}
	return (true);
}

bool	ft_alloc_int_array(t_int_array *out, size_t len)
{
	out->len = len;
	out->array = ft_calloc(out->len, sizeof(int));
	return (out->array);
}

bool	ft_parse_input(t_int_array *out, int ac, char *av[])
{
	size_t		index;

	if (!ft_alloc_int_array(out, ac))
		return (false);
	index = 0;
	while (av[index])
	{
		if (!ft_atoi_to(&av[index], &out->array[ac - 1 - index]))
			return (free(out->array), false);
		index++;
	}
	return (ft_check_double(out));
}
