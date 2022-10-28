/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:08:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/25 16:13:24 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	cost_b_in_a(t_stacks st, t_best_index *idx)
{
	int		value;
	t_range	range_a;

	value = ft_get(st.st[B], idx->b);
	idx->a = st.st[A].size;
	while (idx->a)
	{
		range_a.first = ft_get(st.st[A], idx->a);
		range_a.last = ft_get(st.st[A], idx->a - 1);
		if (range_a.first < value && value < range_a.last)
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
		idx.cost_b = ft_relative_index(idx.b, st.st[B].size - 1);
		idx.cost_b += ft_below_median(st.st[B], idx.b);
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

	inst_a = ft_r_or_rr(*st, A, idx.a) * (!!idx.cost_a);
	inst_b = ft_r_or_rr(*st, B, idx.b) * (!!idx.cost_b);
	if (inst_a && inst_a == inst_b)
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

static void	ft_last_rotate_a(t_stacks *st)
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
	ft_last_rotate_a(st);
}
