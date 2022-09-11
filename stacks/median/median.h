/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:00:06 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/11 17:40:18 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIAN_H
# define MEDIAN_H

# include "parse.h"

typedef enum e_bound {
	MIN,
	Q1,
	MEDIAN,
	Q2,
	MAX,
	MAX_BOUND
}	t_bound;

typedef enum e_chunks {
	C1 = (1 << 0),
	C2 = (1 << 1),
	C3 = (1 << 2),
	C4 = (1 << 3),
	M1 = C1 | C2,
	M2 = C3 | C4,
	MAX_CHUNKS = 5,
	CHUNKS_ERROR = 0
}	t_chunks;

typedef int	t_median[MAX_BOUND];

bool		ft_find_n_medians(t_int_array tab, int *med);
t_chunks	ft_witch_chunk(t_median median, int value);
#endif
