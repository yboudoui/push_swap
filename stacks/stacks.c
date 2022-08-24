/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/24 10:11:34 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static bool	ft_alloc_stack_ab(t_stacks *out, int len)
{
	out->a.data = ft_calloc(len, sizeof(t_int_ptr *));
	out->b.data = ft_calloc(len, sizeof(t_int_ptr *));
	return (out->a.data && out->b.data);
}

static bool	ft_set_stacks(t_stacks *out, int index)
{
	out->a.last_index = out->tab.len;
	out->b.last_index = 0;
	while (index--)
	{
		out->a.data[index] = &out->tab.array[index];
		out->b.data[index] = NULL;
	}
	return (true);
}

bool	ft_new_stacks(t_stacks *out, int ac, char *av[])
{
	if (!ft_parse_input(&out->tab, ac, av))
		return (false);
	if (!ft_alloc_stack_ab(out, ac))
		return (false);
	if (!ft_set_stacks(out, ac))
		return (false);
	return (true);
}

void	ft_free_stacks(t_stacks out)
{
	free(out.a.data);
	free(out.b.data);
	free(out.tab.array);
}


static bool	ft_find_n_medians(t_int_array .data, int n_medians)
{
	size_t	chunk_size;
	size_t	L;
	size_t	R;

	size_t	index;
	size_t	index_b;

	chunk_size = out.len / n_medians;
	index = 0;
	while (index < out.len)
	{
		index_b = index;
		while (++index_b < out.len)
		{
			L += (out.array[index] > out.array[index_b]);
			R += (out.array[index] < out.array[index_b]);
		}
		index++;
	}
	return (true);
}
