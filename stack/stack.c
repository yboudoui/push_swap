/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:09:49 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/15 16:59:24 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static bool	stack_set_memory(t_stack_data *out, size_t size)
{
	if (!mem_new(&out->tab, mem_size_new(sizeof(int), size)))
		return (false);
	if (!mem_new(&out->sta, mem_size_new(sizeof(int *), size)))
		return (false);
	if (!mem_new(&out->stb, mem_size_new(sizeof(int *), size)))
		return (false);
	return (true);
}

static bool	stack_iterator_set_sta()
{

}

static bool	stack_map_input(t_stack_data *input, t_stack_iterator it)
{
	if (!mem_map(input->tab, it))
		return (false);
	if (!mem_map(input->sta, stack_iterator_set_sta))
		return (false);
	if (!mem_map(input->stb, stack_iterator_set_stb))
		return (false);
	return (true);
	it.iterator(it.data, index, current)
}

bool	stack_data_new(t_stack_data *out, t_stack_iterator it)
{
	if (1
	&& stack_set_mem(out, it.data.nmemb)
	&& mem_map(out->tab, it, data)
	&& mem_map(out->a, it, out->tab))
		return (true);
	out->instruction = g_instruction;
	return (true);
}
