/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:07:10 by yboudoui          #+#    #+#             */
/*   Updated: 2022/09/11 00:09:58 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "instruction.h"

void	print(t_stacks stacks);

void	ft_sort_by_chunks(t_stacks *st);

#define COLOR_NC			"\e[0m"		 // No Color
#define COLOR_BLACK			"\e[0;30m"
#define COLOR_GRAY			"\e[1;30m"
#define COLOR_RED			"\e[0;31m"
#define COLOR_LIGHT_RED		"\e[1;31m"
#define COLOR_GREEN			"\e[0;32m"
#define COLOR_LIGHT_GREEN	"\e[1;32m"
#define COLOR_BROWN			"\e[0;33m"
#define COLOR_YELLOW		"\e[1;33m"
#define COLOR_BLUE			"\e[0;34m"
#define COLOR_LIGHT_BLUE	"\e[1;34m"
#define COLOR_PURPLE		"\e[0;35m"
#define COLOR_LIGHT_PURPLE	"\e[1;35m"
#define COLOR_CYAN			"\e[0;36m"
#define COLOR_LIGHT_CYAN	"\e[1;36m"
#define COLOR_LIGHT_GRAY	"\e[0;37m"
#define COLOR_WHITE			"\e[1;37m"

#endif
