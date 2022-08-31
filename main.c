/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/31 15:34:04 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_both(t_stacks *st, t_instruction a, t_instruction b)
{
	if (b == SB && a == SA)
		ft_do_instruction(st, SS);
	else if (b == RB && a == RA)
		ft_do_instruction(st, RR);
	else if (b == RRB && a == RRA)
		ft_do_instruction(st, RRR);
	else
	{
		ft_do_instruction(st, b);
		ft_do_instruction(st, a);
	}
}

void	ft_sort_by_chunks(t_stacks *st)
{
	t_instruction	a;
	t_instruction	b;

	
	while (!ft_are_in_chunck(*st, A, C1 | C4))
	{
		a = NO_INSTRUCTION;
		b = NO_INSTRUCTION;
		if (ft_is_in_chunck(*st, A, -1, C2 | C3))
			ft_do_instruction(st, PB);
		if (ft_at_least_two_elements(st->st[B]) && ft_is_in_chunck(*st, B, -1, C2))
			b = RB;
		if (ft_is_in_chunck(*st, A, -1, C1 | C4))
			a = RA;
		ft_both(st, a, b);
	}
/*
	if (ft_get(st->st[B], -1) < ft_get(st->st[B], -2))
	{
		if (0
			|| (ft_is_in_chunck(*st, A, -1, M2) && ft_is_in_chunck(*st, A, -2, M1))
			|| (ft_is_in_chunck(*st, A, -1, C4) && ft_is_in_chunck(*st, A, -2, C3))
			|| (ft_is_in_chunck(*st, A, -1, C2) && ft_is_in_chunck(*st, A, -2, C1))
			|| (ft_is_in_chunck(*st, A, -1, M1) && ft_is_in_chunck(*st, A, -2, M2))
		)
			ft_do_instruction(st, SS);
	}
	print(*st);
*/
	while (st->st[A].last_index)
	{
		ft_do_instruction(st, PB);
		if (ft_is_in_chunck(*st, B, -1, C1))
			ft_do_instruction(st, RB);
	}
}

bool	ft_find_greatest(t_stacks st, int *output, int *index)
{
	int	idx;
	int	tmp;

	idx = st.st[B].last_index;
	if (!idx)
		return (false);
	idx -= 1;
	(*output) = ft_get(st.st[B], idx);
	while (idx--)
	{
		tmp = ft_get(st.st[B], idx);
		if (*output < tmp)
		{
			(*output) = tmp;
			(*index) = idx;
		}
	}
	return (true);
}

void	third(t_stacks *st)
{
	int	greatest;
	int	index;
	int	middle;

	index = 0;
	greatest = 0;
	middle = st->st[B].last_index / 2;
	if (!ft_find_greatest(*st, &greatest, &index))
		return ;
	if (index < middle)
		while (ft_get(st->st[B], -1) != greatest)
			ft_do_instruction(st, RRB);
	else
		while (ft_get(st->st[B], -1) != greatest)
			ft_do_instruction(st, RB);
	ft_do_instruction(st, PA);
}

void	ft_sort(t_stacks *st)
{
	ft_sort_by_chunks(st);
	print(*st);
	while (!ft_is_sorted(*st))
	{
		third(st);
		print(*st);
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (ft_new_stacks(&stacks, ac - 1, av + 1))
	{
		ft_sort(&stacks);
		return (ft_free_stacks(stacks), 0);
	}
	return (write(1, "error\n", 6), -1);
}
