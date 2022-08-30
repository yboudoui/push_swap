/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 07:28:07 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/30 13:38:19 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	ft_sa(t_stacks *stacks)
{
	ft_swap(&stacks->st[A]);
}

void	ft_sb(t_stacks *stacks)
{
	ft_swap(&stacks->st[B]);
}

void	ft_ss(t_stacks *stacks)
{
	ft_swap(&stacks->st[A]);
	ft_swap(&stacks->st[B]);
}
