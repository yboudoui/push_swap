/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:05:34 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/29 12:55:21 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#define COLOR_NC			"\e[0m"		 // No Color
#define COLOR_BLACK			"\e[0;30m"
#define COLOR_GRAY			"\e[1;30m"
#define COLOR_RED			"\e[0;31m"
#define COLOR_LIGHT_RED		"\e[1;31m"
#define COLOR_GREEN			"\e[0;32m"
#define COLOR_LIGHT_GREEN	"\e[1;32m"
#define COLOR_BROWN			"\e[0;33m"
#define COLOR_YELLOW		"\e[1;33m"
#define COLOR_BLUE			"\e[0;34m"
#define COLOR_LIGHT_BLUE	"\e[1;34m"
#define COLOR_PURPLE		"\e[0;35m"
#define COLOR_LIGHT_PURPLE	"\e[1;35m"
#define COLOR_CYAN			"\e[0;36m"
#define COLOR_LIGHT_CYAN	"\e[1;36m"
#define COLOR_LIGHT_GRAY	"\e[0;37m"
#define COLOR_WHITE			"\e[1;37m"

static char	*get_color(t_stacks st, int *ptr)
{
	if (!ptr)
		return (COLOR_NC);

	if (*ptr <= st.median[1])
	{
		if (*ptr <= st.median[0])
			return (COLOR_YELLOW);
		return (COLOR_RED);
	}
	if (*ptr > st.median[2])
		return (COLOR_GREEN);
	return (COLOR_BLUE);
}

static void	print_int_ptr(char *color, int *ptr, bool show)
{
	if (show)
		printf("[ %11p - ", ptr);
	else
		printf("[");
	if (!ptr)
		printf("%11c ]", '-');
	else
		printf("%s%11d%s ]", color, *ptr, COLOR_NC);
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
		print_int_ptr(get_color(stacks, stacks.a.data[index]), stacks.a.data[index], show_addr);
		print_int_ptr(get_color(stacks, stacks.b.data[index]), stacks.b.data[index], show_addr);
	}
	printf("\n");
}


