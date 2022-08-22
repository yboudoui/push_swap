/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:33:23 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/22 19:24:01 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "stack.h"

typedef int*	t_int_ptr;

typedef struct s_stack {
	t_int_ptr	*data;
	size_t		current_size;
}	t_stack;

void	ft_swap(t_stack d);
void	ft_push(t_stack a, t_int_ptr *i);
void	ft_rotate(t_stack d);
#endif
