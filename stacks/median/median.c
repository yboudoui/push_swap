/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:59:10 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/30 12:43:04 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "median.h"

static void	ft_last_element_is_median(int pivot, t_int_array tab, int *median)
{
	size_t	index;
	size_t	diff;

	diff = 0;
	index = tab.len;
	while (index--)
		diff += (tab.array[index] < pivot);
	tab.len -= 1;
	if (diff == 0)
		median[MIN] = pivot;
	if (diff == (tab.len / 4))
		median[Q1] = pivot;
	if (diff == (tab.len / 2))
		median[MEDIAN] = pivot;
	if (diff == tab.len - (tab.len / 4))
		median[Q2] = pivot;
	if (diff == tab.len)
		median[MAX] = pivot;
}

bool	ft_find_n_medians(t_int_array tab, int *med)
{
	size_t	tab_index;
	size_t	med_index;

	med_index = 3;
	tab_index = tab.len;
	while (tab_index--)
		ft_last_element_is_median(tab.array[tab_index], tab, med);
	return (true);
}

t_chunks	ft_witch_chunk(t_median median, int value)
{
	if (median[MIN] <= value && value < median[Q1])
		return (C1);
	if (median[Q1] <= value && value < median[MEDIAN])
		return (C2);
	if (median[MEDIAN] <= value && value < median[Q2])
		return (C3);
	if (median[Q2] <= value && value <= median[MAX])
		return (C4);
	return (CHUNKS_ERROR);
}

bool	ft_value_is_in_chunck(t_median median, int value, t_chunks chunks)
{
	return (ft_witch_chunk(median, value) == chunks);
}

