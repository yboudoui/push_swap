/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/28 15:10:37 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef bool	(*t_fp_eval)(int, int);

bool	ft_lower_than(int a, int b)
{
	return (a < b);
}

bool	ft_lower_or_equal_than(int a, int b)
{
	return (a <= b);
}

bool	ft_have(t_stack st, t_fp_eval eval, int a)
{
	size_t	index;

	index = st.last_index - 1;
	while (index)
		if (eval(*st.data[index--], a))
			return (true);
	return (false);
}

int	ft_get_last(t_stack st)
{
	return (*st.data[st.last_index - 1]);
}

void	ft_sort(t_stacks *stacks)
{
	t_instruction	inst;

	while (ft_have(stacks->a, ft_lower_or_equal_than, stacks->median[1]))
	{
		if (ft_get_last(stacks->a) <= stacks->median[1])
			inst = PB;
		else
			inst = RA;
		ft_do_instruction(stacks, inst);
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (!ft_new_stacks(&stacks, ac - 1, av + 1))
		return (write(1, "error\n", 6), -1);
	print(stacks);
	ft_sort(&stacks);
	print(stacks);
	return (ft_free_stacks(stacks), 0);
}
