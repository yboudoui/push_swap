/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:32:31 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/15 14:39:20 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_io.h"

bool	mem_io_set_size_of_output_type(t_mem_io *data, size_t sizeOfType)
{
	return (ft_calloc_to(data->output.data, sizeOfType, data->input->size.nmemb));
}
/*
static void	*mem_get_index(t_mem input, size_t index)
{
	return (input.data + (input.size * index));
}
*/
bool	mem_io_map(t_iterator func, t_mem_io io)
{
	t_index	index;

	index = 0;
	while (index < io.input->size.nmemb)
	{
		if (!func(io, index))
			return (false);
		index++;
	}
	return (true);
}
