/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 07:37:48 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/23 09:08:32 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	ft_rra(t_stacks *stacks)
{
	ft_rotate(true, &stacks->a);
}

void	ft_rrb(t_stacks *stacks)
{
	ft_rotate(true, &stacks->b);
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rotate(true, &stacks->a);
	ft_rotate(true, &stacks->b);
}
