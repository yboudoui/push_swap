/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/10 15:30:17 by yboudoui         ###   ########.fr       */
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
	out->st[A].size = out->tab.len;
	out->st[B].size = 0;
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
	if (stacks.st[A].size != stacks.tab.len)
		return (false);
	while ((1 + index) < stacks.st[A].size)
	{
		if (*stacks.st[A].data[index] <= *stacks.st[A].data[index + 1])
			return (false);
		index++;
	}
	return (true);
}

int	mod(int a, int b)
{
	int	modulo;

	modulo = a % b;
	if (modulo < 0)
		modulo += b;
	return (modulo);
}

int	ft_get(t_stack st, int index)
{
	return (*st.data[mod(index, st.size)]);
}

bool	ft_at_least_two_elements(t_stack st)
{
	return (st.size > 1);
}

bool	ft_is_in_chunck(t_stacks st, t_stack_name st_name, int index, t_chunks chunks)
{
	int	value;

	if (st.st[st_name].size < 2)
		return (false);
	value = ft_get(st.st[st_name], index);
	return (ft_witch_chunk(st.median, value) & chunks);
}

bool	ft_are_in_chunck(t_stacks st, t_stack_name st_name, t_chunks chunks)
{
	int	index;

	index = st.st[st_name].size;
	while (index--)
		if (!ft_is_in_chunck(st, st_name, index, chunks))
			return (false);
	return (true);
}
