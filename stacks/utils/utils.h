/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:16:46 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/22 18:20:35 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "memory.h"
# include "is_charset.h"
# include <limits.h>
# include <unistd.h>
# include <stddef.h>

bool	ft_atoi_to(char **str, int *result);
int		mod(int a, int b);

#endif
