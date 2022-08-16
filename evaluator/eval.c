/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:40:36 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/09 13:37:19 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_isspace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

typedef bool	(*t_str_until)(void *);

char	*void_to_char(void *input)
{
	return ((char *)input);
}

char	*ft_str_increment(char *input)
{
	return (input + 1);
}

char	*ft_str_next(char **input)
{

}

char	*ft_str_process_until(char **str, t_str_until u, t_str_process p)
{
	while (u(*str))
		p(*str);
}

char	*ft_skip_character(char **str, t_str_until u, )
{
	while (until(**str))
		(*str)++;
	return (*str);
}
