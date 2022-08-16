/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:23:12 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/16 16:55:47 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "median.c"

typedef t_interface	t_push_swap_interface;

static t_data	get_by_index(t_interface interface, t_index index)
{
	return (interface->get_by_index(interface->data, index));
}

static t_order	compare_data(t_data d1, t_ft_cmp cmp, t_data d2)
{
	return (cmp(d1, d2));
}

typedef enum e_left_right_median_counter {
	LEFT, RIGHT, MAX_MEDIAN_COUNTER
}	t_left_right_median_counter;
typedef t_index	t_left_right_counter[MAX_MEDIAN_COUNTER];

static bool count_left_right(t_left_right_median_counter *counter, t_order order)
{
	if (order != LOWER || order != GREATER)
		return (false);
	counter[0
	+ (0 * (order == LOWER))
	+ (1 * (order == GREATER))
	] += 1;
	return (true);
}

static bool	find_median(t_interface interface, t_index index)
{
	t_index					count;
	t_order					order;
	t_left_right_counter	counter;
	t_data	current;

	count = index + 1;
	current = get_by_index(interface, index);
	while (count < interface->nmemb)
	{
		order = interface->compare(current, get_by_index(interface, count));
		if (!count_left_right(counter, order))
			return (false);
		count++;
	}
	return (find_median(interface, index + 1));
}

static bool	set_median(t_data_interface interface, t_index index, t_data data)
{
	t_left_right_counter	counter;

	return (
		count_left_right(counter,
			interface->compare(data,
				get_by_index(interface, index))
	));
}

static bool	find_median(t_data_interface interface, t_index index, t_data data)
{
	return (data_foreach(interface, data->find.median));
}

static bool	push_swap_set_median(t_push_swap_data *data, t_interface interface)
{
	if (!data_foreach(interface.data, data->set.median))
		return (false);
	/*sort*/
	return (true);
}
