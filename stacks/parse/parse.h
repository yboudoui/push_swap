/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:27:54 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/22 17:39:49 by yboudoui         ###   ########.fr       */
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

bool	ft_parse_input(t_int_array *out, char *av[]);
#endif
