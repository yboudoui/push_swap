/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 07:37:48 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/30 13:37:51 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	ft_rra(t_stacks *stacks)
{
	ft_rotate(true, &stacks->st[A]);
}

void	ft_rrb(t_stacks *stacks)
{
	ft_rotate(true, &stacks->st[B]);
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rotate(true, &stacks->st[A]);
	ft_rotate(true, &stacks->st[B]);
}
