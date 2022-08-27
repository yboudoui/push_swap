/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/27 13:33:09 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "instruction.h"

#include <stdio.h>

void	print_int_ptr(int *ptr)
{
	printf("[ %11p - ", ptr);
	if (!ptr)
		printf("%11c ]", '-');
	else
		printf("%11d ]", *ptr);
}

void	print(t_stacks stacks)
{
	size_t	index;

	printf("\n------------------------------------------------------\n");
	index = stacks.median.len;
	printf("median len : %zu\n", index);
	while (index--)
		printf("%d ", stacks.median.array[index]);
	printf("\n------------------------------------------------------\n");
	index = stacks.tab.len;
	printf("stack\t\t\tA\t\tB\n");
	printf("size\t\t\t%zu\t\t%zu\n", stacks.a.last_index, stacks.b.last_index);
	while (index--)
	{
		printf("\n-%11zu- ", index);
		print_int_ptr(stacks.a.data[index]);
		print_int_ptr(stacks.b.data[index]);
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (!ft_new_stacks(&stacks, ac - 1, av + 1))
		return (print(stacks), printf("error\n"), -1);
	print(stacks);

	ft_ra(&stacks);
	print(stacks);

	ft_sa(&stacks);
	print(stacks);

	ft_pb(&stacks);
	ft_pb(&stacks);
	print(stacks);

	ft_sb(&stacks);
	ft_rra(&stacks);
	print(stacks);

	ft_ra(&stacks);
	print(stacks);

	ft_sa(&stacks);
	print(stacks);


	ft_pb(&stacks);
	ft_pb(&stacks);
	ft_pb(&stacks);
	ft_pb(&stacks);
	ft_pb(&stacks);

	print(stacks);

	ft_sa(&stacks);
	print(stacks);

	ft_sb(&stacks);
	print(stacks);

	ft_free_stacks(stacks);
	return (0);
}
