/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/29 16:16:54 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_instruction	ft_eval_b(t_stacks *stacks)
{
	if (stacks->b.last_index > 1 && ft_get(stacks->b, -1) > stacks->median[0] && ft_get(stacks->b, -2) < stacks->median[0])
 		return (SB);

	if (ft_get(stacks->a, -1) <= stacks->median[1])
		return (PB);

	if (ft_get(stacks->a, -1) <= stacks->median[2])
 		return (RRB);

	if (ft_get(stacks->a, -1) >= stacks->median[2])
		return (PB);
	return (NO_INSTRUCTION);
}

t_instruction	ft_eval_a(t_stacks *stacks)
{
	if (ft_get(stacks->a, -1) <= stacks->median[1])
		return (NO_INSTRUCTION);
//	if (ft_get(stacks->a, -1) > stacks->median[2])
//		return (PB);
//	else
	return (RRA);
//	return (NO_INSTRUCTION);
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
