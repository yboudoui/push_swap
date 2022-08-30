/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:00:06 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/30 13:28:21 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIAN_H
# define MEDIAN_H

# include "parse.h"

typedef enum e_bound {
	MIN, Q1, MEDIAN, Q2, MAX,
	MAX_BOUND
}	t_bound;

typedef enum e_chunks {
	C1, C2, C3, C4, MAX_CHUNKS, CHUNKS_ERROR
}	t_chunks;

typedef int	t_median[MAX_BOUND];

bool	ft_find_n_medians(t_int_array tab, int *med);

t_chunks	ft_witch_chunk(t_median median, int value);
bool		ft_value_is_in_chunck(t_median median, int value, t_chunks chunks);
#endif
