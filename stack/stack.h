/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:11:06 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/15 16:35:55 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "mem.h"

typedef struct s_stack_data		t_stack_data;
typedef int						t_stack_type;
typedef struct s_stack_iterator	t_stack_iterator;

struct s_stack_iterator {
	t_data	data;
	t_index	max_count;
	bool	(*iterator)(t_data, t_index, t_stack_type *);
};

bool	stack_data_new(t_stack *out, t_stack_iterator it);

struct s_stack_data {
	t_mem			tab;
	t_mem			sta;
	t_mem			stb;
	t_instruction	instruction;
}	t_stack_data;

#endif
