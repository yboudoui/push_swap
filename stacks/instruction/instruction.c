/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:33:09 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/22 19:40:44 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

static void	ft_int_ptr_swap(t_int_ptr *a, t_int_ptr *b)
{
	t_int_ptr	tmp;

	tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

void	ft_swap(t_stack s)
{
	if (s.current_size < 2)
		return ;
	ft_int_ptr_swap(
		s.data[s.current_size],
		s.data[s.current_size - 1]
	);
}

void	ft_push(t_stack from, t_stack to)
{
	ft_int_ptr_swap(
		from.data[from.current_size],
		to.data[to.current_size + 1]
	);
	from.current_size -= 1;
	to.current_size += 1;
}

void	ft_rotate(bool reverse, t_stack s)
{
	t_int_ptr	*tmp;

	tmp = s.data[(current_size * !reverse)];
	ft_memmove(
		&s.data[!reverse],
		&s.data[reverse],
		(s.current_size - 1) * sizeof(int *)
	);
	s.data[(current_size * reverse)] = tmp;
}

/*
void	ft_rotate(t_stack s)
{
	t_int_ptr	*tmp;

	tmp = s.data[current_size];
	ft_memmove(
		&s.data[1],
		&s.data[0],
		(s.current_size - 1) * sizeof(int *)
	);
	s.data[0] = tmp;
}

void	ft_reverse_rotate(t_stack d)
{
	t_int_ptr	*tmp;

	tmp = s.data[0];
	ft_memmove(
		&s.data[0],
		&s.data[1],
		(s.current_size - 1) * sizeof(int *)
	);
	s.data[current_size] = tmp;
}
*/
