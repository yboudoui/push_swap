/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/22 15:13:13 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	ft_free_stacks(t_stacks out)
{
	free(out.a);
	free(out.b);
	free(out.tab.array);
}

bool	ft_new_stacks(t_stacks *out, char *av[])
{
	size_t	index;

	if (!ft_parse_input(&out->tab, av))
		return (false);
	out->a = ft_calloc(out->tab.len, sizeof(int **));
	out->b = ft_calloc(out->tab.len, sizeof(int **));
	if (!out->a || !out->b)
		return (ft_free_stacks(*out), false);
	index = 0;
	while (index < out->tab.len)
	{
		out->a[index] = &out->tab.array[index];
		out->b[index] = NULL;
		index++;
	}
	return (true);
}
