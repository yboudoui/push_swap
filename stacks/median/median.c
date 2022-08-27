/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:59:10 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/27 18:09:18 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "median.h"
#include <stdio.h>

static bool	ft_last_element_is_median(size_t chunks_size, int pivot, t_int_array tab)
{
	size_t	left;
	size_t	right;
	size_t	index;

	left = 0;
	right = (chunks_size % 2);
	index = tab.len;
	while (index--)
	{
		left += (pivot > tab.array[index]);
		right += (pivot < tab.array[index]);
	}
	if (!right || !left)
		return (false);
	printf("right %zu left %zu\n", right, left);
	double tmp= 0;
	if (right > left)
		tmp = right / left;
	if (left > right)
		tmp = left / right;
	printf("tmp %f\n", tmp);
	if (!tmp || tmp == chunks_size)
		return (true);
	printf("false\n");
	return (false);
}

bool	ft_find_n_medians(t_int_array tab, t_int_array *med)
{
	size_t	med_index;
	size_t	tab_index;
	size_t	chunks_size;

	chunks_size = tab.len / med->len;
	printf("chunks_size %zu \n", chunks_size);
	med_index = 0;
	tab_index = tab.len;
	while (tab_index-- && med_index < med->len)
	{
		if (ft_last_element_is_median(chunks_size, tab.array[tab_index], tab))
			med->array[med_index++] = tab.array[tab_index];
	}
	return (true);
}
