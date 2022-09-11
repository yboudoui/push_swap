/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:05:55 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/11 17:46:47 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

typedef struct s_best_index {
	long int	a;
	long int	b;
	int			cost_a;
	int			cost_b;
}	t_best_index;

void	ft_sort_by_values(t_stacks *st);
#endif
