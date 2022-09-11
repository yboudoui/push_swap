/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:33:09 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/08 18:07:08 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

typedef struct s_execution_set{
	void	(*func)(t_stacks *);
	char	*print;
	size_t	len;
}	t_execution_set;

const t_execution_set	g_instruction_set[MAX_INSTRUCTION_SET] = {
	[PA] = {ft_pa, "pa", 2},
	[PB] = {ft_pb, "pb", 2},
	[SA] = {ft_sa, "sa", 2}, [SB] = {ft_sb, "sb", 2}, [SS] = {ft_ss, "ss", 2},
	[RA] = {ft_ra, "ra", 2}, [RB] = {ft_rb, "rb", 2}, [RR] = {ft_rr, "rr", 2},
	[RRA] = {ft_rra, "rra", 3}, [RRB] = {ft_rrb, "rrb", 3}, [RRR] = {ft_rrr, "rrr", 3},
};

static void	ft_print_instruction(t_execution_set inst)
{
	if (!PRINT_INSTRUCTION)
		return ;
	write(1, inst.print, inst.len);
	write(1, "\n", 1);
}

void	ft_do_instruction(t_stacks *stacks, t_instruction set)
{
	t_execution_set	inst;

	if (set <= 0 || set >= MAX_INSTRUCTION_SET)
		return ;
	inst = g_instruction_set[set];
	ft_print_instruction(inst);
	return (inst.func(stacks));
}
