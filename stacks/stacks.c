/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/31 09:47:46 by yboudoui         ###   ########.fr       */
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
	if (stacks.st[A].last_index != stacks.tab.len)
		return (false);
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

bool	ft_at_least_two_elements(t_stack st)
{
	return (st.last_index > 1);
}

bool	ft_is_in_chunck(t_stacks st, t_stack_name st_name, int index, t_chunks chunks)
{
	return (ft_witch_chunk(st.median, ft_get(st.st[st_name], index)) & chunks);
}

bool	ft_are_in_chunck(t_stacks st, t_stack_name st_name, t_chunks chunks)
{
	int	index;

	index = st.st[st_name].last_index;
	while (index--)
		if (!ft_is_in_chunck(st, st_name, index, chunks))
			return (false);
	return (true);
}
