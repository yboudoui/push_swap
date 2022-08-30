/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/30 14:13:14 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_eval_lst(t_stacks *st, t_stack_name st_name, t_chunks ch, t_instruction inst)
{
	int	value;

	value = ft_get(st->st[st_name], -1);
	while (ft_value_is_in_chunck(st->median, value, ch))
	{
		ft_do_instruction(st, inst);
		value = ft_get(st->st[st_name], -1);
	}
}

t_instruction	ft_eval_b(t_stacks *stacks)
{
	const t_median *median = &stacks->median;
	int				value;
/*
	if (stacks->b.last_index > 1 && ft_get(stacks->b, -1) > stacks->median[0] && ft_get(stacks->b, -2) < stacks->median[0])
 		return (SB);
*/

	value = ft_get(stacks->st[B], -1);
	if (stacks->st[B].last_index > 1 && value > (*median)[Q1] && ft_get(stacks->st[B], -2) <= (*median)[Q1])
 		return (RB);

	ft_eval_lst(stacks, A, C1, PB);
	ft_eval_lst(stacks, A, C2, PB);
/*
	value = ft_get(stacks->a, -1);
	if (value <= (*median)[MEDIAN])
		return (PB);
*/
	return (NO_INSTRUCTION);
}

t_instruction	ft_eval_a(t_stacks *stacks)
{
	t_median	*median;
	int			value;

	median = &stacks->median;
	value = ft_get(stacks->st[A], -1);

	if (ft_value_is_in_chunck(*median, value, C3))
		return (RA);
	if (ft_value_is_in_chunck(*median, value, C4))
		return (RA);

	return (NO_INSTRUCTION);
}

typedef t_instruction	(*t_eval_st)(t_stacks *);

void	ft_both(t_stacks *st, t_eval_st eval_a, t_eval_st eval_b)
{
	t_instruction	a;
	t_instruction	b;

	a = eval_a(st);
	b = eval_b(st);
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

void	ft_sort(t_stacks *stacks)
{
	char	c = '\n';

	while (c == '\n' && !ft_is_sorted(*stacks))
	{
		ft_both(stacks, ft_eval_a, ft_eval_b);
		c = getchar();
		print(*stacks);
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (ft_new_stacks(&stacks, ac - 1, av + 1))
	{
		print(stacks);
		ft_sort(&stacks);
		return (ft_free_stacks(stacks), 0);
	}
	return (write(1, "error\n", 6), -1);
}
