/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:44:37 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/11 17:08:47 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static bool	ft_cmp_last_two(t_stacks st, t_stack_name name)
{
	return (1
		&& ft_at_least_two_elements(st.st[name])
		&& (ft_get(st.st[name], -1) < ft_get(st.st[name], -2))
	);
}

void	ft_sort_by_chunks(t_stacks *st)
{
	t_instruction	inst;
	int				last_value;

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
