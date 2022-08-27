/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:27:54 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/27 12:35:44 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "memory.h"
# include "is_charset.h"
# include <stddef.h>

typedef struct s_int_array {
	int		*array;
	size_t	len;
}	t_int_array;

bool	ft_alloc_int_array(t_int_array *out, size_t len);
bool	ft_parse_input(t_int_array *out, int ac, char *av[]);
#endif
