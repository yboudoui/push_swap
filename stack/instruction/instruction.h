/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:38:03 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/13 13:42:37 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "mem.h"

typedef struct s_instruction {
	t_do	sa;
	t_do	sb;
	t_do	ss;
	t_do	pa;
	t_do	pb;
	t_do	ra;
	t_do	rb;
	t_do	rr;
	t_do	rra;
	t_do	rrb;
	t_do	rrr;
}	t_instruction;

#endif
