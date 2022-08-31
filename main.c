/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/31 17:44:30 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

////// consider to associate chuncks flag with corresponding value, it may help

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

bool	ft_cmp_last_two(t_stacks st, t_stack_name name)
{
	return (1
		&& ft_at_least_two_elements(st.st[name])
		&& (ft_get(st.st[name], -1) < ft_get(st.st[name], -2))
	);
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
		if (ft_is_in_chunck(*st, B, -1, C2) && ft_cmp_last_two(*st, B))
			b = RB;
		if (ft_is_in_chunck(*st, A, -1, C1 | C4))
			a = RA;
		ft_both(st, a, b);
	}
	while (st->st[A].last_index != 2)
	{
		ft_do_instruction(st, PB);
		if (ft_is_in_chunck(*st, B, -1, C1))
			ft_do_instruction(st, RB);
	}
	if (!ft_cmp_last_two(*st, A))
		ft_do_instruction(st, SA);
}

/*

///////	old part making bad performance one 500 elements
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
*/

int	ft_relative_index(t_stacks st, t_stack_name name, int index)
{
	int	index;
	int	size;
	int	middle;

	index = 0;
	size = st.st[name].last_index;
	middle = size / 2;
	if (index <= middle)
		return (index);
	return (size - index);
}

int	ft_find_best_element_A(t_stacks st, t_chunks ch)
{
	int	index;
	int	index_tmp;
	int	best_index;
	int	count;

	size = st.st[B].last_index;
	count = size;
	index = size;
	best_index = size;
	while (--index)
	{
		if (!ft_is_in_chunck(st, B, index, ch))
			continue ;
		index_tmp = ft_relative_index(st, B, index);
		if (count > index_tmp)
		{
//////////////	still unable to figure out how to evaluate number instruction of A
/////////////	maybe making a function to get me the best value to be on top of stack A
			if (
			count = index_tmp;
			best_index = index;
		}
	}
	return (best_index);
}

void	third(t_stacks *st)
{
	int	index;
	int	size;
	int	middle;

	while (ft_are_in_chunck(*st, B, C4))
	{
		size = st->st[B].last_index;
		middle = size / 2;
		index = ft_find_best_element_A(*st, C4);

/////// try to make a generique function applied to A and B
		if (index < middle)
			while (ft_get(st->st[B], -1) != size)
				ft_do_instruction(st, RRB);
		else
			while (ft_get(st->st[B], -1) != size)
				ft_do_instruction(st, RB);
///////
		ft_do_instruction(st, PA);
	}
}


void	ft_sort(t_stacks *st)
{
	ft_sort_by_chunks(st);
//	print(*st);
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
