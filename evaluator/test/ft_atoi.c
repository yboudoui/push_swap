/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:21:40 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/13 18:49:15 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_data {
	int		sign;
	int		valu;
	char	**str;
}	t_data;

int	ft_find_sign(char c)
{
	return (
	((int[3]){0, -1, 1})[
		(0) +
		(1 * (c == '-')) +
		(2 * (c == '+' || ft_isdigit(c))
	])
}

void	ft_update_result(void *input)
{
	t_data	*output;

	output = input;
	output->result *= 10;
	output->result += (**output->str - '0');
	(*output->str)++;
}

bool	str_is_digit(void *str)
{
	return (ft_isdigit(*str));
}

void	skip_character(void *input)
{
	char	**data;

	data = input;
	(*data) += 1;
}

static t_eval skip_spaces = loop_new(ft_isspace, skip_character);
static t_eval update_sign = cond_new(find_sign, set_sign);
static t_eval update_valu = loop_new(ft_isdigit, set_result);

int	ft_atoi(const char *nptr)
{
	t_data	data;
	t_eval	atoi;

	data = (t_data){0, 0, &nptr}
	atoi = eval_new(&data, {skip_spaces, update_sign, update_valu, NULL});
	eval_atoi(atoi);
	return (data.valu);
}
