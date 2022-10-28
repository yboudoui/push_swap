/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/25 17:10:06 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	index_of_smallest(t_stack st)
{
	size_t	index;
	int		value;
	int		g_index;

	g_index = 0;
	index = 0;
	value = ft_get(st, index);
	while (index < st.size - 1)
	{
		if (value > ft_get(st, index + 1))
		{
			g_index = index + 1;
			value = ft_get(st, index + 1);
		}
		index++;
	}
	return (g_index);
}

bool	ft_is_reverse_sorted(t_stack st)
{
	size_t	index;
	int		offset;
	int		value;

	index = 0;
	offset = index_of_smallest(st);
	while (index < st.size - 1)
	{
		value = ft_get(st, index + offset);
		index++;
		if (value > ft_get(st, index + offset))
			return (false);
	}
	return (true);
}

static void	send_to_b(t_stacks *st)
{
	int	last_value;

	last_value = 0;
	while (st->st[A].size > 3)
	{
		last_value = ft_get(st->st[A], -1);
		if (last_value == st->median[MIN] || last_value == st->median[MAX])
			ft_do_instruction(st, RA);
		else
			ft_do_instruction(st, PB);
	}
	if (ft_is_reverse_sorted(st->st[A]))
		ft_do_instruction(st, SA);
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (!ft_new_stacks(&stacks, ac - 1, av + 1))
		return (ft_free_stacks(&stacks), -1);
	if (stacks.tab.len > 5)
		ft_sort_by_chunks(&stacks);
	else
		send_to_b(&stacks);
	ft_sort_by_values(&stacks);
	return (ft_free_stacks(&stacks), 0);
}
