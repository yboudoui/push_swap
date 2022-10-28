/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:13:20 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/25 17:09:00 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static bool	ft_alloc_stack_ab(t_stacks *out, int len)
{
	out->st[A].data = ft_calloc(len, sizeof(t_int_ptr *));
	out->st[B].data = ft_calloc(len, sizeof(t_int_ptr *));
	return (out->st[A].data && out->st[B].data);
}

static bool	ft_set_stacks(t_stacks *out, int index)
{
	out->st[A].size = out->tab.len;
	out->st[B].size = 0;
	while (index--)
	{
		out->st[A].data[index] = &out->tab.array[index];
		out->st[B].data[index] = NULL;
	}
	return (true);
}

bool	ft_new_stacks(t_stacks *out, int ac, char *av[])
{
	if (!out)
		return (false);
	(*out) = (t_stacks){0};
	if (!ft_parse_input(&out->tab, ac, av))
		return (write(2, "Error\n", 6), false);
	if (!ft_alloc_stack_ab(out, ac))
		return (write(2, "Error\n", 6), false);
	if (!ft_set_stacks(out, ac))
		return (write(2, "Error\n", 6), false);
	if (ft_is_sorted(*out))
		return (false);
	return (ft_find_n_medians(out->tab, out->median));
}

void	ft_free_stacks(t_stacks *out)
{
	free(out->st[A].data);
	out->st[A].data = NULL;
	free(out->st[B].data);
	out->st[B].data = NULL;
	free(out->tab.array);
	out->tab.array = NULL;
}
