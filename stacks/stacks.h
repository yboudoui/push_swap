/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:27:54 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/22 17:39:49 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "parse.h"

typedef struct s_stacks {
	t_int_array	tab;
	int			**a;
	int			**b;
}	t_stacks;

bool	ft_new_stacks(t_stacks *out, char *av[]);
void	ft_free_stacks(t_stacks out);
#endif
