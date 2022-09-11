/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:57:07 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/08 18:00:46 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include "stacks.h"

void	ft_swap(t_stack *s);
void	ft_push(t_stack *from, t_stack *to);
void	ft_rotate(bool reverse, t_stack *s);

#endif
