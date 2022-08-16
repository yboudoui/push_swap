/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:49:07 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/15 16:38:31 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline t_const_mem	def_arg(int ac, char *av[])
{
	return (mem_define(++av, mem_size_new(sizeof(char *), --ac)));
}

static bool	atoi_input(t_data *data, t_index index, t_stack_type *value)
{
	t_input	*input;

	(void)index;
	input = data;
	(*value) = atoi(*input->av);
	return (true);
}

bool	init_stack(t_stack *output, int ac, char **av)
{
	t_mem_io	io;
	t_const_mem	arg;

	arg = def_arg(ac, ac);
	if (!stack_new(output, atoi_input))
		return (false);
	mem_new(&output->tab, mem_size_new(sizeof(int), arg.nmemb));

	if (!mem_map(atoi_iterator, io))
		return (false);
	/*set stack a and b*/
	return (true);
}



t_stack_iterator	input(int ac, char **av)
{
	t_stack_iterator	output;

	return (output);
}
