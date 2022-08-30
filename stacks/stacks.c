/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/30 13:32:58 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static bool	ft_alloc_stack_ab(t_stacks *out, int len)
{
	out->st[A].data = ft_calloc(len, sizeof(t_int_ptr *));
	out->st[B].data = ft_calloc(len, sizeof(t_int_ptr *));
	if (!out->st[A].data || !out->st[B].data)
	{
		free(out->st[A].data);
		free(out->st[B].data);
		return (false);
	}
	return (true);
}

static bool	ft_set_stacks(t_stacks *out, int index)
{
	out->st[A].last_index = out->tab.len;
	out->st[B].last_index = 0;
	while (index--)
	{
		out->st[A].data[index] = &out->tab.array[index];
		out->st[B].data[index] = NULL;
	}
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
	free(out.st[A].data);
	free(out.st[B].data);
	free(out.tab.array);
}

bool	ft_is_sorted(t_stacks stacks)
{
	size_t	index;

	index = 0;
	while ((1 + index) < stacks.st[A].last_index)
	{
		if (*stacks.st[A].data[index] <= *stacks.st[A].data[index + 1])
			return (false);
		index++;
	}
	return (true);
}

int	ft_get(t_stack st, long int index)
{
	if (index < 0)
		index = st.last_index + index;

	if (index < 0)
		return (0);
/*
	_abs = index * ((index > 0) - (index < 0));
	if (_abs > st.last_index)
		index %= st.last_index;
	printf("__%ld\n", index);
*/
	return (*st.data[index]);
}
