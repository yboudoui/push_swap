/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 07:35:24 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/23 09:39:27 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	ft_ra(t_stacks *stacks)
{
	ft_rotate(false, &stacks->a);
}

void	ft_rb(t_stacks *stacks)
{
	ft_rotate(false, &stacks->b);
}

void	ft_rr(t_stacks *stacks)
{
	ft_rotate(false, &stacks->a);
	ft_rotate(false, &stacks->b);
}
