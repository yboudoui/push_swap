/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/11 17:36:01 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (ft_new_stacks(&stacks, ac - 1, av + 1))
	{
		ft_sort_by_chunks(&stacks);
		ft_sort_by_values(&stacks);
		return (ft_free_stacks(stacks), 0);
	}
	return (write(1, "error\n", 6), -1);
}
