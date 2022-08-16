/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:19:22 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/09 15:16:14 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	*data;

typedef struct	s_loop {
	t_bool	eval;
	t_make	process;
}	t_loop;

typedef struct	s_eval {
	void	*data;
	void	(*eval[])(void *);
/*
	t_bool		is_valide;
	t_make		process;
	t_condition	condition;
	t_loop		loop;
*/
}	t_eval;

inline void	eval_processus(t_eval e)
{
	return(e.process(e.data));
}

inline void	eval_condition(t_eval e)
{
	return (condition_eval(e.condition, e.data));
}

inline void	eval_until(t_eval e)
{
	while (eval_condition(e))
		eval_processus(e);
}

/*
typedef struct	s_process {
	void	(*process)()
}	t_process;

typedef struct	s_until {
	t_process	(*until)()
}	t_until;

t_until	with(void *input)
{
	data = input;
	return ((t_until){})
}

void	ft_process_until(void *data, bool (*until)(void *), bool (*process)(void *))
{
	while (until(data))
		process(data);
}

char	*str;

with(str).until(ft_isdigit).process(update_result);
*/
