/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:56:24 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/28 14:15:31 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static void	ft_int_ptr_swap(t_int_ptr *a, t_int_ptr *b)
{
	t_int_ptr	tmp;

	tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

void	ft_swap(t_stack *s)
{
	size_t	index;

	if (s->last_index < 1)
		return ;
	index = s->last_index - 1;
	ft_int_ptr_swap(
		&s->data[index],
		&s->data[index - 1]);
}

void	ft_push(t_stack *from, t_stack *to)
{
	if (from->last_index == 0)
		return ;
	ft_int_ptr_swap(
		&(from->data[from->last_index - 1]),
		&(to->data[to->last_index]));
	from->last_index -= 1;
	to->last_index += 1;
}

void	ft_rotate(bool reverse, t_stack *s)
{
	t_int_ptr	tmp;
	size_t		index;

	if (s->last_index < 2)
		return ;
	index = s->last_index - 1;
	tmp = s->data[(index * !reverse)];
	ft_memmove(
		&(s->data[!reverse]),
		&(s->data[reverse]),
		(index) * sizeof(int *));
	s->data[(index * reverse)] = tmp;
}
