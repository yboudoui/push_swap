/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/22 17:29:19 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int	ft_relative_index(int index, int size)
{
	if ((size / 2) > index)
		return (index);
	return (size - index);
}

bool	ft_is_sorted(t_stacks stacks)
{
	size_t	index;
	int		value;

	index = 0;
	if (stacks.st[A].size != stacks.tab.len)
		return (false);
	value = (*stacks.st[A].data[index++]);
	while (index < stacks.st[A].size)
	{
		if (value <= *stacks.st[A].data[index])
			return (false);
		value = (*stacks.st[A].data[index++]);
	}
	return (true);
}

int	ft_get(t_stack st, int index)
{
	return (*st.data[mod(index, st.size)]);
}

bool	ft_is_in_chunck(t_stacks st, t_name name, int index, t_chunks chunks)
{
	int	value;

	if (st.st[name].size < 2)
		return (false);
	value = ft_get(st.st[name], index);
	return (ft_witch_chunk(st.median, value) & chunks);
}

bool	ft_are_in_chunck(t_stacks st, t_name name, t_chunks chunks)
{
	int	index;

	index = st.st[name].size;
	while (index--)
		if (!ft_is_in_chunck(st, name, index, chunks))
			return (false);
	return (true);
}
