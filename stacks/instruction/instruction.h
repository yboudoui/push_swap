/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:33:23 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/28 14:28:12 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "base.h"
# include <unistd.h>

# ifndef PRINT_INSTRUCTION
# define PRINT_INSTRUCTION 1
# endif

void	ft_sa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ft_ss(t_stacks *stacks);

void	ft_pa(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);

void	ft_ra(t_stacks *stacks);
void	ft_rb(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);

void	ft_rra(t_stacks *stacks);
void	ft_rrb(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);

typedef enum e_instruction {
	SA, SB, SS,
	PA, PB,
	RA, RB, RR,
	RRA, RRB, RRR,
	MAX_INSTRUCTION_SET
}	t_instruction;

void	ft_do_instruction(t_stacks *stacks, t_instruction set);
#endif
