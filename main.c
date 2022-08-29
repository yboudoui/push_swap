/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:56:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/29 13:10:14 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef bool	(*t_fp_eval)(int, int);

bool	ft_lower_than(int a, int b)
{
	return (a < b);
}

bool	ft_greater_than(int a, int b)
{
	return (a > b);
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

#include <stdio.h>

void	ft_eval_b(t_stacks *stacks)
{
	if (ft_last(stacks->b) > stacks->median[0])
		ft_do_instruction(stacks, RB);
}

void	ft_separate(t_stacks *stacks)
{
	char	c = '\n';
	int					change;
	const t_instruction	inst[2] = {RA, PB};

	while (c == '\n' && ft_have(stacks->a, ft_lower_or_equal_than, stacks->median[1]))
	{
		change = (ft_last(stacks->a) <= stacks->median[1]);
		ft_do_instruction(stacks, inst[change]);
		if (inst[change] == PB)
			ft_eval_b(stacks);
		c = getchar();
		print(*stacks);
	}
}

bool	ft_splited(t_stack st, int quartil)
{
	int				change;
	size_t			index;
	const t_fp_eval	func[2] = {ft_lower_than, ft_greater_than};

	change = 0;
	index = 0;
	while (index < st.last_index)
	{
		if (*st.data[index] == quartil)
		{
			change += 1;
			index++;
		}
		if (!func[change](*st.data[index], quartil))
			return (false);
		index++;
	}
	return (true);
}

void	ft_split(t_stacks *stacks)
{
	while (!ft_splited(stacks->b, stacks->median[0]))
	{
		if (ft_last(stacks->b) < stacks->median[0])
			ft_do_instruction(stacks, RRB);
//		else if (ft_first(stacks->b) > stacks->median[0])
//			ft_do_instruction(stacks, RB);
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (!ft_new_stacks(&stacks, ac - 1, av + 1))
		return (write(1, "error\n", 6), -1);
	print(stacks);


	ft_separate(&stacks);
//	ft_split(&stacks);

	print(stacks);
	return (ft_free_stacks(stacks), 0);
}
