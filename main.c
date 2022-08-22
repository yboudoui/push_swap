/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/22 19:31:19 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

#include <stdio.h>

void	ft_itoa(char *out, int n)
{
	int			size;
	long int	m;
	long int	ntmp1;
	long int	ntmp2;

	size = 0;
	while (size < 20)
		out[size++] = 0;
	m = n;
	size = (m <= 0);
	ntmp1 = m * ((m >= 0) - (m < 0));
	while (ntmp1 > 0)
	{
		ntmp1 /= 10;
		size++;
	}
	out[0] = '-';
	ntmp2 = m * ((m >= 0) - (m < 0));
	while (--size >= (m < 0))
	{
		out[size] = '0' + (ntmp2 % 10);
		ntmp2 /= 10;
	}
}

char	*print_int_ptr(char *str, int *ptr)
{
	if (!ptr)
		str = "-";
	else
		ft_itoa(str, *ptr);
	return (str);
}

void	print(t_stacks stacks)
{
	size_t	index;
	char	str[20];

	index = stacks.tab.len;
	printf("	A		B\n");
	while (index--)
	{
		printf("[ %11s ]	[ %11s ]\n",
			print_int_ptr(str, stacks.a[index]),
			print_int_ptr(str, stacks.b[index])
		);
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	(void)ac;
	if (!ft_new_stacks(&stacks, av + 1))
		return (printf("error\n"), -1);
	print(stacks);
	ft_free_stacks(stacks);
	return (0);
}
