/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:05:34 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/11 00:09:58 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


static char	*get_color(t_stacks st, int *ptr)
{
	if (!ptr)
		return (COLOR_NC);
	if (*ptr <= st.median[MEDIAN])
	{
		if (*ptr <= st.median[Q1])
			return (COLOR_YELLOW);
		return (COLOR_RED);
	}
	if (*ptr > st.median[Q2])
		return (COLOR_BLUE);
	return (COLOR_GREEN);
}

static void	print_int_ptr(char *color, int *ptr, bool show)
{
	if (show)
		printf("[ %11p - ", ptr);
	else
		printf("[");
	if (!ptr)
		printf("%11c ]", ' ');
	else
		printf("%s%11d%s ]", color, *ptr, COLOR_NC);
}

static void	print_median(t_stacks stacks)
{
	size_t	index;

	printf("\n------------------------------------------------------\n");
	index = MAX_BOUND;
	printf("median len : %zu\n", index);
	while (index--)
		printf("%d ", stacks.median[index]);
	printf("\n------------------------------------------------------\n");
}

void	print(t_stacks stacks)
{
	size_t	index;
	bool	show_addr = false;

	print_median(stacks);
	printf("stack\t\t\tA\t\tB\n");
	printf("size\t\t\t%u\t\t%u\n", stacks.st[A].size, stacks.st[B].size);
	index = stacks.tab.len;
	while (index--)
	{
		printf("\n-%4zu- ", index);
		print_int_ptr(get_color(stacks, stacks.st[A].data[index]), stacks.st[A].data[index], show_addr);
		print_int_ptr(get_color(stacks, stacks.st[B].data[index]), stacks.st[B].data[index], show_addr);
	}
	printf("\n");
}


