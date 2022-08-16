/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:56:35 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/16 16:20:23 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	sort_make(t_push_swap_data *data, t_push_swap_interface interface)
{
	return (true);
}

static bool	sort_check(t_push_swap_data *data, t_push_swap_interface interface)
{
	return (true);
}



typedef bool	(*t_ft_push_swap_sort)(t_push_swap_data *, t_push_swap_interface);

bool	push_swap_init(t_stack_data *data, t_push_swap_interface interface)
{
	const t_ft_push_swap_sort g_sort[2] = {sort_make, sort_check};

	if (!data)
		return (false);
	if (!push_swap_set_median(data, interface))
		return (false);
	if (!g_sort[BONUS](data, interface))
		return (false);
	return (true);
}
