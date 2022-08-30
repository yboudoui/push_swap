/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 07:35:24 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/30 13:37:30 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	ft_ra(t_stacks *stacks)
{
	ft_rotate(false, &stacks->st[A]);
}

void	ft_rb(t_stacks *stacks)
{
	ft_rotate(false, &stacks->st[B]);
}

void	ft_rr(t_stacks *stacks)
{
	ft_rotate(false, &stacks->st[A]);
	ft_rotate(false, &stacks->st[B]);
}
