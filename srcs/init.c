/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 13:26:52 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 10:03:14 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		rtrn_err(char **tab)
{
	ft_free_2d(tab);
	return (0);
}

t_param	*init_param(void)
{
	t_param *p;

	p = malloc(sizeof(t_param));
	if (p)
	{
		p->cnt = 0;
		p->print = 0;
		return (p);
	}
	return (0);
}
