/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:59:10 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/28 15:43:37 by yboudoui         ###   ########.fr       */
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
	if (diff == (tab.len / 4))
		median[0] = pivot;
	if (diff == (tab.len / 2))
		median[1] = pivot;
	if (diff == tab.len - (tab.len / 4))
		median[2] = pivot;
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
