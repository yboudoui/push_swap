/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_io.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:33:23 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/14 15:03:39 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_IO_H
# define MEM_IO_H

# include "mem.h"

typedef size_t				t_index;
typedef struct s_mem_io		t_mem_io;
typedef bool				(*t_iterator)(t_mem_io, t_index);

struct	s_mem_io {
	t_absolut_mem_ref	input;
	t_mem				output;
};

bool	mem_io_set_size_of_output_type(t_mem_io *data, size_t sizeOfType);
bool	mem_io_map(t_iterator func, t_mem_io io);

#endif
