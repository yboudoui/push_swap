/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:33:09 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/29 15:21:04 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

typedef struct s_instruction_set{
	void	(*func)(t_stacks *);
	char	*print;
	size_t	len;
}	t_instruction_set;

const t_instruction_set	g_instruction_set[MAX_INSTRUCTION_SET] = {
	{ft_sa, "sa", 2},
	{ft_sb, "sb", 2},
	{ft_ss, "ss", 2},
	{ft_pa, "pa", 2},
	{ft_pb, "pb", 2},
	{ft_ra, "ra", 2},
	{ft_rb, "rb", 2},
	{ft_rr, "rr", 2},
	{ft_rra, "rra", 3},
	{ft_rrb, "rrb", 3},
	{ft_rrr, "rrr", 3},
};

static void	ft_print_instruction(t_instruction_set inst)
{
	if (!PRINT_INSTRUCTION)
		return ;
	write(1, inst.print, inst.len);
	write(1, "\n", 1);
}

void	ft_do_instruction(t_stacks *stacks, t_instruction set)
{
	t_instruction_set	inst;

	if (set < 0 || set >= MAX_INSTRUCTION_SET)
		return ;
	inst = g_instruction_set[set];
	ft_print_instruction(inst);
	return (inst.func(stacks));
}
