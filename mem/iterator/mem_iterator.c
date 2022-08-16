/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_iterator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:30 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/15 17:20:25 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_iterator.h"


static bool	mem_eval_iterator(t_mem_iterator it, t_index idex, t_mem *mem)
{
	return (it.iterator(it.data, idx, mem_get_by_index(mem, idx)))
}

bool	mem_map(t_mem *input, t_mem_iterator it)
{
	t_index	index;

	index = 0;
	while (index < input->nmemb)
	{
		if (!mem_eval_iterator(it, input, index))
			return (false);
		index++;
	}
	return (true);
}
