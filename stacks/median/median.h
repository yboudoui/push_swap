/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:00:06 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/27 13:17:26 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIAN_H
# define MEDIAN_H

# include "parse.h"

typedef struct s_left_right {
	size_t	left;
	size_t	right;
}	t_left_right;

bool	ft_find_n_medians(t_int_array tab, t_int_array *median);

#endif
