/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_value_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:42:26 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/23 17:58:20 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_instruction	ft_r_or_rr(t_stacks st, t_name name, int index)
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

t_range	range_of_indexes(t_stack st, int first_index, int last_index)
{
	t_range	out;

	out.first = ft_get(st, first_index);
	out.last = ft_get(st, last_index);
	return (out);
}
