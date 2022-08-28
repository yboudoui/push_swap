/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:59:10 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/28 11:08:33 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "median.h"

static bool	ft_last_element_is_median(int pivot, t_int_array tab)
{
	size_t	index;
	size_t	diff;

	diff = 0;
	index = tab.len;
	while (index--)
		diff += (tab.array[index] < pivot);
	tab.len -= 1;
	return (0
		|| (diff == (tab.len / 4))
		|| (diff == (tab.len / 2))
		|| (diff == tab.len - (tab.len / 4))
	);
}

bool	ft_find_n_medians(t_int_array tab, int *med)
{
	size_t	tab_index;
	size_t	med_index;

	med_index = 3;
	tab_index = tab.len;
	while (tab_index-- && med_index)
		if (ft_last_element_is_median(tab.array[tab_index], tab))
			med[--med_index] = tab.array[tab_index];
	return (true);
}
