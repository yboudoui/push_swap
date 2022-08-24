/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/24 10:06:08 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
/*
static bool	ft_parse_string_to_int_array(t_int_array *out, char *str)
{
	size_t	index;
	char	*tmp;

	(*out) = (t_int_array){NULL, 0};
	tmp = str;
	while (*tmp)
		out->len += ft_skiped(&tmp, ft_notspace);
	out->array = ft_calloc(out->len, sizeof(int));
	if (!out->array)
		return (false);
	index = 0;
	while (*str && index < out->len)
		if (!ft_atoi_to(&str, &out->array[index++]))
			return (free(out->array), false);
	return (true);
}

static bool	ft_join_int_array(t_int_array *out, t_int_array in)
{
	int	*tmp;

	tmp = ft_calloc(out->len + in.len, sizeof(int));
	if (!tmp)
		return (false);
	ft_memcpy(tmp, out->array, (out->len * sizeof(int)));
	ft_memcpy(tmp + out->len, in.array, (in.len * sizeof(int)));
	free(in.array);
	free(out->array);
	return (*out = (t_int_array){tmp, out->len + in.len}, true);
}
*/
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

static bool	ft_alloc_int_array(t_int_array *out, size_t len)
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
