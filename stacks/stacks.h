/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:27:54 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/24 06:44:16 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "parse.h"

typedef int*	t_int_ptr;

typedef struct s_stack {
	t_int_ptr	*data;
	size_t		last_index;
}	t_stack;

typedef struct s_stacks {
	t_int_array	tab;
	t_stack		a;
	t_stack		b;
}	t_stacks;

bool	ft_new_stacks(t_stacks *out, int ac, char *av[]);
void	ft_free_stacks(t_stacks out);
#endif
