/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:27:54 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/31 07:31:38 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "median.h"

typedef int*	t_int_ptr;

typedef struct s_stack {
	t_int_ptr	*data;
	size_t		last_index;
}	t_stack;

typedef enum e_stack_name {
A, B, MAX_STACK_NAME
}	t_stack_name;

typedef struct s_stacks {
	t_int_array	tab;
	t_median	median;
	t_stack		st[MAX_STACK_NAME];
}	t_stacks;

bool	ft_new_stacks(t_stacks *out, int ac, char *av[]);
void	ft_free_stacks(t_stacks out);
bool	ft_is_sorted(t_stacks stacks);

int		ft_get(t_stack st, long int index);
bool	ft_at_least_two_elements(t_stack st);
bool	ft_is_in_chunck(t_stacks st, t_stack_name st_name, int index, t_chunks chunks);
bool	ft_are_in_chunck(t_stacks st, t_stack_name st_name, t_chunks chunks);

#endif
