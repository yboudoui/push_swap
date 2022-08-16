/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:56:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/16 16:53:24 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BONUS
# define PRINT_INSTRUCTION 1
# else
# define PRINT_INSTRUCTION 0
# endif

typedef t_data t_ptr;
typedef t_index t_idx;

typedef enum e_cmp {LOWER = -1, EQUAL = 0, GREATER = 1}	t_cmp;

typedef t_cmp	(*t_ft_cmp)(t_ptr, t_ptr);
typedef t_ptr	(*t_ft_idx)(t_ptr, t_idx);

typedef enum e_instruction {
	PA, PB,
	SA, SB, SS,
	RA, RB, RR,
	RRA, RRB, RRR,
	MAX_INSTRUCTION,
}	t_instruction;


typedef struct s_push_swap_interface {
	t_data_interface	data;
	t_ft_do 			instruction[MAX_INSTRUCTION];
}	t_push_swap_interface;

#endif

/*-----------------------------------------*/

typedef struct s_data_interface {
	t_ptr		data;
	t_idx		nmemb;
	t_ft_idx	get_by_index;
	t_ft_cmp	compare;
}	t_data_interface;

typedef struct s_data_iterator {
	t_data	data;
	bool	(*iterator)(t_data_interface, t_index, t_data);
}

bool	data_foreach(t_data_interface interface, t_data_iterator iterator)
{
	t_idx	index;

	index = 0;
	while (index++ < interface->nmemb)
		if (!iterator.iterator(interface, index, iterator.data))
			return (false);
	return (true);
}
