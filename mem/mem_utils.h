/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:47:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/14 19:42:48 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_UTILS_H
# define MEM_UTILS_H

# include <stdlib.h>
# include "mem_size.h"

typedef union	u_data {
	void	*data;
	void	**ptr;
}	t_data __attribute__ ((__transparent_union__));

t_data	ft_memset(t_data ptr, int c, size_t n);
t_data	ft_calloc(t_mem_size size);
bool	ft_calloc_to(t_data output, size_t nmemb, size_t size);

#endif
/*

typedef enum e_error {
	error,
	no_error
} t_error_signal;

typedef struct s_error {
	t_error_signal	signal;
	char			*message;
} t_error_message;

typedef union u_error {
	t_error_signal	signal;
	t_error_message	message;
}	t_error __attribute__ ((__transparent_union__));

void A (void)
{
	t_error_message oo;

	oo = (t_error_message){error, "error"};

	check_error(oo);
}

void	check_error(t_error err)
{
	err.signal 
}
*/
