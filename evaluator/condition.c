/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:59:37 by yboudoui          #+#    #+#             */
/*   Updated: 2022/08/09 15:04:15 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef bool	(*t_bool)(void *);
typedef void	(*t_make)(void *);

typedef struct	s_condition {
	t_bool	eval;
	t_make	succes;
	t_make	failur;
}	t_condition;

inline void	condition_eval(t_condition *e, void *data)
{
	if (e.eval(data))
		e.succes(data);
	else
		e.failur(data);
}
