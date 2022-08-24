/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 07:32:59 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/23 09:02:27 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	ft_pa(t_stacks *stacks)
{
	ft_push(&stacks->b, &stacks->a);
}

void	ft_pb(t_stacks *stacks)
{
	ft_push(&stacks->a, &stacks->b);
}
