/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:05:55 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/23 17:25:16 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "instruction.h"

typedef struct s_best_index {
	long int	a;
	long int	b;
	int			cost_a;
	int			cost_b;
}	t_best_index;

void			ft_sort_by_values(t_stacks *st);

typedef struct s_range {
	int	first;
	int	last;
}	t_range;

void			ft_sort_by_chunks(t_stacks *st);
t_instruction	ft_r_or_rr(t_stacks st, t_name name, int index);
void			ft_do_n_instruction(t_stacks *st, int n, t_instruction inst);
bool			ft_below_median(t_stack st, int index);
t_range			range_of_indexes(t_stack st, int first_index, int last_index);

#endif
