/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:23:47 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/16 16:30:13 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIAN_H
# define MEDIAN_H

typedef enum e_median {
	FIRST, SECOND, THIRD,
	MAX_MEDIAN,
}	t_median;

typedef enum e_stack {
	A, B, MAX_STACKS
}	t_stack;

typedef struct	s_median {
	t_data	median[MAX_MEDIAN];
	
}	t_median;

typedef struct s_push_swap_data {
	t_median	median;
	t_data		stacks[MAX_STACKS];
}	t_push_swap_data;
#endif

