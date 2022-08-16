/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:29:34 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/15 17:01:18 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include "mem_utils.h"

typedef struct	s_mem		t_mem;
typedef t_mem*				t_mem_ref;
typedef const t_mem			t_const_mem;
typedef t_mem* const		t_mem_const_ref;
typedef const t_mem* const	t_absolut_mem_ref;

typedef enum e_mem_state	t_mem_state;
typedef t_data				t_mem_data;
typedef void				(*t_do)(t_data);

enum e_mem_state {UNSET, STACK, HEAP};
struct s_mem {
	t_mem_state	state;
	t_mem_data	data;
	t_mem_size	size;
};

t_const_mem	mem_new(t_mem_size size);
t_const_mem	mem_define(t_data data, t_mem_size size);
t_data		mem_get_by_index(t_mem input, t_index idx);

#endif
