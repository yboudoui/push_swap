/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:05:34 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/28 15:45:13 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_int_ptr(int *ptr, bool show)
{
	if (show)
		printf("[ %11p - ", ptr);
	else
		printf("[");
	if (!ptr)
		printf("%11c ]", '-');
	else
		printf("%11d ]", *ptr);
}

void	print(t_stacks stacks)
{
	size_t	index;
	bool	show_addr = false;

	printf("\n------------------------------------------------------\n");
	index = 3;
	printf("median len : %zu\n", index);
	while (index--)
		printf("%d ", stacks.median[index]);
	printf("\n------------------------------------------------------\n");
	index = stacks.tab.len;
	printf("stack\t\t\tA\t\tB\n");
	printf("size\t\t\t%zu\t\t%zu\n", stacks.a.last_index, stacks.b.last_index);
	while (index--)
	{
		printf("\n-%4zu- ", index);
		print_int_ptr(stacks.a.data[index], show_addr);
		print_int_ptr(stacks.b.data[index], show_addr);
	}
	printf("\n");
}


