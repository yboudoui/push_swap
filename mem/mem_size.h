/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_size.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:38:35 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/15 14:41:57 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_SIZE_H
# define MEM_SIZE_H

# include <stddef.h>
# include <stdbool.h>

typedef struct	s_mem_size {
	size_t	size;
	size_t	nmemb;
}	t_mem_size;

t_mem_size	mem_size_new(size_t size_of_type, size_t number_of_member);
size_t		mem_size_total(t_mem_size size);
bool		mem_size_check(t_mem_size size);

#endif
