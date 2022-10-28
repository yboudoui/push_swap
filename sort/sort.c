/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:44:37 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/22 16:44:07 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static bool	ft_cmp_last_two(t_stacks st, t_name name)
{
	return (1
		&& (st.st[name].size > 1)
		&& (ft_get(st.st[name], -1) < ft_get(st.st[name], -2))
	);
}

static void	send_second_and_third_chunk_to_b(t_stacks *st)
{
	t_instruction	inst;

	while (!ft_are_in_chunck(*st, A, C1 | C4))
	{
		inst = NO_INSTRUCTION;
		if (ft_is_in_chunck(*st, A, -1, C2 | C3))
			ft_do_instruction(st, PB);
		if (ft_is_in_chunck(*st, B, -1, C2) && ft_cmp_last_two(*st, B))
			inst |= RB;
		if (ft_is_in_chunck(*st, A, -1, C1 | C4))
			inst |= RA;
		ft_do_instruction(st, inst);
	}
}

static void	send_first_and_last_chunk_to_b(t_stacks *st)
{
	int	last_value;

	while (st->st[A].size > 2)
	{
		last_value = ft_get(st->st[A], -1);
		if (last_value == st->median[MIN] || last_value == st->median[MAX])
			ft_do_instruction(st, RA);
		else
			ft_do_instruction(st, PB);
		if (ft_is_in_chunck(*st, B, -1, C1))
			ft_do_instruction(st, RB);
	}
	if (ft_cmp_last_two(*st, A))
		ft_do_instruction(st, SA);
}

void	ft_sort_by_chunks(t_stacks *st)
{
	send_second_and_third_chunk_to_b(st);
	send_first_and_last_chunk_to_b(st);
}
