/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:27:54 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/10 15:38:23 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "median.h"

typedef int*	t_int_ptr;

typedef struct s_stack {
	// store the index in a, in b and the cost
	/*
	int pos_a;	// index in a
	int pos_b;	// index in b
	int cost;	// of moving to be
	int ismax_a;
	int ismin_a;
	int abs_max;
	int abs_min;

	*/
	t_int_ptr		*data;	//value -> if you bubble sort this is the index
	unsigned int	size;
}	t_stack;

typedef enum e_stack_name {
	A = (1 << 0),
	B = (1 << 1),
	MAX_STACK_NAME = B + 1
}	t_stack_name;

typedef enum e_instruction_set {
	_P = (1 << 2),
	_S = (1 << 3),
	_R = (1 << 4),
	_RR = (1 << 5),
}	t_instruction_set;

typedef enum e_instruction {
	NO_INSTRUCTION,
	PA = _P|A, PB = _P|B,
	SA = _S|A, SB = _S|B, SS = _S|A|B,
	RA = _R|A, RB = _R|B, RR = _R|A|B,
	RRA = _RR|A, RRB = _RR|B, RRR = _RR|A|B,
	MAX_INSTRUCTION_SET = RRR + 1,
}	t_instruction;

typedef struct s_stacks {
	t_int_array	tab;
	t_median	median;
	t_stack		st[MAX_STACK_NAME];
}	t_stacks;

/*
s_number {
	int value;
	int pos_a;
	int pos_b;
	int cost;

} t_number

*/

bool	ft_new_stacks(t_stacks *out, int ac, char *av[]);
void	ft_free_stacks(t_stacks out);
bool	ft_is_sorted(t_stacks stacks);

int	mod(int a, int b);
int		ft_get(t_stack st, int index);
bool	ft_at_least_two_elements(t_stack st);
bool	ft_is_in_chunck(t_stacks st, t_stack_name st_name, int index, t_chunks chunks);
bool	ft_are_in_chunck(t_stacks st, t_stack_name st_name, t_chunks chunks);

#endif
