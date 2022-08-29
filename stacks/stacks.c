/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/29 12:35:29 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static bool	ft_alloc_stack_ab(t_stacks *out, int len)
{
	out->a.data = ft_calloc(len, sizeof(t_int_ptr *));
	out->b.data = ft_calloc(len, sizeof(t_int_ptr *));
	if (!out->a.data || !out->b.data)
	{
		free(out->a.data);
		free(out->b.data);
		return (false);
	}
	return (true);
}

static bool	ft_set_stacks(t_stacks *out, int index)
{
	out->a.last_index = out->tab.len;
	out->b.last_index = 0;
	while (index--)
	{
		out->a.data[index] = &out->tab.array[index];
		out->b.data[index] = NULL;
	}
	ft_memset(out->median, 0, sizeof(int) * 3);
	return (true);
}

bool	ft_new_stacks(t_stacks *out, int ac, char *av[])
{
	if (!ft_parse_input(&out->tab, ac, av))
		return (false);
	if (!ft_alloc_stack_ab(out, ac))
		return (false);
	if (!ft_set_stacks(out, ac))
		return (false);
	return (ft_find_n_medians(out->tab, out->median));
}

void	ft_free_stacks(t_stacks out)
{
	free(out.a.data);
	free(out.b.data);
	free(out.tab.array);
}

bool	ft_is_sorted(t_stacks stacks)
{
	size_t	index;

	index = 0;
	while ((1 + index) < stacks.a.last_index)
	{
		if (*stacks.a.data[index] <= *stacks.a.data[index + 1])
			return (false);
		index++;
	}
	return (true);
}

int	ft_last(t_stack st)
{
	return (*st.data[st.last_index - 1]);
}

int	ft_first(t_stack st)
{
	return (*st.data[0]);
}
