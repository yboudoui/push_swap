/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:08:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/11 17:35:30 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_instruction	ft_R_or_RR(t_stacks st, t_stack_name name, int index)
{
	const int	middle = st.st[name].size / 2;

	return (name | (t_instruction_set [2]){_R, _RR}[index < middle]);
}

void	ft_do_n_instruction(t_stacks *st, int n, t_instruction inst)
{
	while (n--)
		ft_do_instruction(st, inst);
}

bool	ft_below_median(t_stack st, int index)
{
	return (index < ((int)st.size - 1) / 2);
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
			return (ft_relative_index(idx->a, st.st[A].size));
		idx->a--;
	}
	return (ft_relative_index(idx->a, st.st[A].size));
}

t_best_index	ft_eval_best_position(t_stacks st)
{
	t_best_index	out;
	t_best_index	idx;
	int				cost_move;

	cost_move = st.tab.len;
	out = (t_best_index){0, 0, 0, 0};
	idx = (t_best_index){0, st.st[B].size, cost_move, cost_move};
	while (idx.b--)
	{
		idx.cost_a = cost_b_in_a(st, &idx);
		idx.cost_b = ft_relative_index(idx.b, st.st[B].size - 1) + ft_below_median(st.st[B], idx.b);
		if (cost_move > (idx.cost_a + idx.cost_b))
		{
			cost_move = (idx.cost_a + idx.cost_b);
			out = (t_best_index){
				mod(idx.a, st.st[A].size),
				mod(idx.b, st.st[B].size),
				idx.cost_a, idx.cost_b,
			};
		}
	}
	return (out);
}

static void	ft_merge_instruction(t_stacks *st, t_best_index idx)
{
	t_instruction	inst_a;
	t_instruction	inst_b;

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
	ft_do_n_instruction(st, idx.cost_a, inst_a);
	ft_do_n_instruction(st, idx.cost_b, inst_b);
}

static void	ft_last_rotate_A(t_stacks *st)
{
	int				index;
	t_instruction	inst;

	index = st->st[A].size - 1;
	while (index && ft_get(st->st[A], index) != st->median[MIN])
		index--;
	inst = RA;
	if (index < ((int)(st->st[A].size - 1) / 2))
		inst = RRA;
	while (ft_get(st->st[A], 0) != st->median[MAX])
		ft_do_instruction(st, inst);
}

void	ft_sort_by_values(t_stacks *st)
{
	while (st->st[B].size)
	{
		ft_merge_instruction(st, ft_eval_best_position(*st));
		ft_do_instruction(st, PA);
	}
	ft_last_rotate_A(st);
}
