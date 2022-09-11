/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/11 15:11:53 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*
void	ft_sort_by_values(t_stacks *st)
{
	t_best_index	idx;
	t_instruction	inst_a;
	t_instruction	inst_b;

	while (!ft_is_sorted(*st))
	{
		idx = ft_eval_best_position(*st);
		inst_a = ft_R_or_RR(*st, A, idx.a);
		inst_b = ft_R_or_RR(*st, B, idx.b);
		printf("%ld[%d] - %ld[%d]\n", idx.a, *st->st[A].data[idx.a], idx.b, *st->st[B].data[idx.b]);
		idx.b = ft_relative_index(*st, B, idx.b);
		idx.a = ft_relative_index(*st, B, idx.a);
		while (idx.a || idx.b)
		{
			inst_a *= (!!idx.a);
			inst_b *= (!!idx.b);
			idx.a -= (!!idx.a);
			idx.b -= (!!idx.b);
			ft_do_instruction(st, inst_a | inst_b);
		}
		ft_do_instruction(st, PA);
		print(*st);
	}
}
*/

bool	ft_B_index_is_between_first_and_last_A(t_stacks st, int index)
{
	int	last_a;
	int	first_a;
	int	value;

	if (st.st[B].size == 0)
		return (false);
	last_a = ft_get(st.st[A], -1);
	first_a = ft_get(st.st[A], 0);
	value = ft_get(st.st[B], index);
	return (last_a > value && value > first_a);
}

void	ft_swap_optimization(t_stacks *st)
{
	t_stack	a;

	a = st->st[A];
	if (0
	|| !ft_B_index_is_between_first_and_last_A(*st, -1)
	|| !ft_B_index_is_between_first_and_last_A(*st, -2)
	|| !ft_B_index_is_between_first_and_last_A(*st, -3)
	|| !ft_B_index_is_between_first_and_last_A(*st, -4))
		return ;
//	print(*st);
	if (0
	|| (ft_get(a, -3) > ft_get(a, -4))
	|| (ft_get(a, -4) > ft_get(a, -1))
	|| (ft_get(a, -1) > ft_get(a, -2)))
		return ;
//	print(*st);
	ft_do_instruction(st, PA);
	ft_do_instruction(st, PA);
	ft_do_instruction(st, SS);
	ft_do_instruction(st, PA);
	ft_do_instruction(st, PA);
//	print(*st);
}


typedef struct s_best_index {
	long int	a;
	long int	b;
	int			cost_a;
	int			cost_b;
}	t_best_index;
/*
int	cost_b_in_a(t_stacks st, t_best_index *idx)
{
	int	cost;
	int	size;
	int	value;

	cost = 0;
	size = st.st[A].size - 1;
	value = ft_get(st.st[B], idx->b);
	if (ft_get(st.st[A], -1) > value && value > ft_get(st.st[A], 0))
		return (0);
	if (ft_get(st.st[A], -1) < value && value < ft_get(st.st[A], 0))
		return (0);
	idx->a = size;
	while (idx->a > 1)
	{
		if (idx->a < (size / 2))
			cost = 0;
		cost += 1;
		printf ("%d cost_b_in_a %d %d \n", ft_get(st.st[B], idx->b), ft_get(st.st[A], idx->a), ft_get(st.st[A], idx->a - 1));
		if (ft_get(st.st[A], idx->a) < value && value < ft_get(st.st[A], idx->a - 1))
			return (cost);
		idx->a--;
	}
	return (cost);
}
*/

int	ft_ri(t_stack st, int index)
{
	int	size;

	size = st.size;
	if ((size / 2) > index)
		return (index);
	return (size - index);
}

int	ft_relative_index(t_stack st, int index)
{
	int	size;

	size = st.size - 1;
	if ((size / 2) > index)
		return (index);
	return (size - index);
}

int	cost_b_in_a(t_stacks st, t_best_index *idx)
{
	int	size;
	int	value;

	size = st.st[A].size - 1;
	value = ft_get(st.st[B], idx->b);
	if (ft_get(st.st[A], -1) > value && value > ft_get(st.st[A], 0))
		return (0);
	if (ft_get(st.st[A], -1) < value && value < ft_get(st.st[A], 0))
		return (0);
	idx->a = size;
	while (idx->a > 1)
	{
		if (ft_get(st.st[A], idx->a) < value && value < ft_get(st.st[A], idx->a - 1))
			return (ft_ri(st.st[A], idx->a));
		idx->a--;
	}
	return (ft_ri(st.st[A], idx->a));
}

bool	ft_below_median(t_stack st, int index)
{
	return (index < ((int)st.size - 1) / 2);
}

t_best_index	ft_eval_best_position(t_stacks st)
{
	t_best_index	out;
	t_best_index	idx;
	int				cost_move;
	int				cost_a;
	int				cost_b;

	out = (t_best_index){0, 0, 0, 0};
	cost_move = st.tab.len;
	cost_a = cost_move;
	cost_b = cost_move;
	idx = (t_best_index){0, st.st[B].size, cost_move, cost_move};
	while (idx.b--)
	{
		cost_a = cost_b_in_a(st, &idx);
		cost_b = ft_relative_index(st.st[B], idx.b) + ft_below_median(st.st[B], idx.b);
		idx.cost_b = cost_b;
		idx.cost_a = cost_a;
/*
		if (1
		&& (ft_below_median(st.st[A], idx.a) && ft_below_median(st.st[B], idx.b))
		)
//		|| (!ft_below_median(st.st[A], idx.a) && !ft_below_median(st.st[B], idx.b)))
		{
			if (cost_b >= cost_a)
			{
				cost_b -= cost_a;
			//	cost_a = 0;
			}
			else
			{
				cost_a -= cost_b;
			//	cost_b = 0;
			}
//			idx.cost_b = cost_b - ((cost_b > cost_a) * cost_a);
//			idx.cost_a = cost_a - ((cost_a > cost_b) * cost_b);
		}
*/
/*		printf("cost_a = %d cost_b = %d | %ld[%d] - %ld[%d]\n",
		cost_a, cost_b,
		idx.a, ft_get(st.st[A], idx.a),
		idx.b, ft_get(st.st[B], idx.b)
		);
*/
		if (cost_move > (cost_a + cost_b))
		{
			cost_move = (cost_a + cost_b);
			out = (t_best_index){
				mod(idx.a, st.st[A].size),
				mod(idx.b, st.st[B].size),
				idx.cost_a, idx.cost_b,
			};
/*		printf("%scost_a = %d cost_b = %d | %ld[%d] - %ld[%d]%s\n",
		COLOR_PURPLE,
		idx.cost_a, idx.cost_b,
		idx.a, ft_get(st.st[A], idx.a),
		idx.b, ft_get(st.st[B], idx.b),
		COLOR_NC
		);
*/
		if (cost_move == 0)
			return (out);
		}
	}
	return (out);
}

void	ft_when_last_B_between_first_and_last_A(t_stacks *st)
{
	int	last_a;
	int	last_b;
	int	first_a;

	first_a = ft_get(st->st[A], 0);
	last_a = ft_get(st->st[A], -1);
	last_b = ft_get(st->st[B], -1);
	if (last_b < last_a && last_b > first_a)
		ft_do_instruction(st, PA);
	while (last_b < last_a && last_b < first_a)
	{
		ft_do_instruction(st, RRA);
		first_a = ft_get(st->st[A], 0);
		last_a = ft_get(st->st[A], -1);
	}
	while (last_b > last_a && last_b > first_a)
	{
		ft_do_instruction(st, RA);
		first_a = ft_get(st->st[A], 0);
		last_a = ft_get(st->st[A], -1);
	}
}

t_instruction	ft_R_or_RR(t_stacks st, t_stack_name name, int index)
{
	const int	middle = st.st[name].size / 2;

	return (name | (t_instruction_set [2]){_R, _RR}[index < middle]);
}
void	ft_sort_by_values(t_stacks *st)
{
	t_best_index	idx;
	t_instruction	inst_a;
	t_instruction	inst_b;
//	int				cost_a = 0;

	while (st->st[B].size)
	{
//		print(*st);
//		ft_swap_optimization(st);
		idx = ft_eval_best_position(*st);
		inst_a = ft_R_or_RR(*st, A, idx.a) * (!!idx.cost_a);
		inst_b = ft_R_or_RR(*st, B, idx.b) * (!!idx.cost_b);
		if (((inst_a & _R) && (inst_b & _R)) || ((inst_a & _RR) && (inst_b & _RR)))
		{
			while (idx.cost_a || idx.cost_b)
			{
				ft_do_instruction(st, inst_a | inst_b);
				idx.cost_a -= (!!idx.cost_a);
				idx.cost_b -= (!!idx.cost_b);
				inst_a *= (!!idx.cost_a);
				inst_b *= (!!idx.cost_b);
			}
		}
		else
		{
			while (idx.cost_a--)
				ft_do_instruction(st, inst_a);
			while (idx.cost_b--)
				ft_do_instruction(st, inst_b);
		}
		ft_do_instruction(st, PA);
//		ft_when_last_B_between_first_and_last_A(st);
	}
	int	index = st->st[A].size - 1;
	while (index && ft_get(st->st[A], index) != st->median[MIN])
		index--;
	inst_a = RA;
	if (index < ((int)(st->st[A].size - 1) / 2))
		inst_a = RRA;
	while (ft_get(st->st[A], 0) != st->median[MAX])
		ft_do_instruction(st, inst_a);
}
int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (ft_new_stacks(&stacks, ac - 1, av + 1))
	{
		ft_sort_by_chunks(&stacks);
		ft_sort_by_values(&stacks);
//		print(stacks);
		if (!ft_is_sorted(stacks))
			printf("error\n");
		return (ft_free_stacks(stacks), 0);
	}
	return (write(1, "error\n", 6), -1);
}
/*
	6
	8
10	4
2	5

8	4
6	5
10	
2	

6	5
8	4
10
2

4
5
6
8
10
2
*/
