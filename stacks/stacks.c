/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/27 13:24:59 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static bool	ft_alloc_stack_ab(t_stacks *out, int len)
{
	if (!ft_alloc_int_array(&out->median, MEDIANS))
		return (false);
	out->a.data = ft_calloc(len, sizeof(t_int_ptr *));
	out->b.data = ft_calloc(len, sizeof(t_int_ptr *));
	if (!out->a.data || !out->b.data)
	{
		free(out->a.data);
		free(out->b.data);
		return (false);
	}
	return (true);
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
	return (ft_find_n_medians(out->tab, &out->median));
}

void	ft_free_stacks(t_stacks out)
{
	free(out.a.data);
	free(out.b.data);
	free(out.tab.array);
}
