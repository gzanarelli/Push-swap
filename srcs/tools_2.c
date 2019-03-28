/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 13:51:48 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 11:49:28 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_lstlenght(t_node *p)
{
	int i;

	i = 0;
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}

void	view(t_list2 *lst)
{
	t_node *p;

	p = lst->head;
	while (p)
	{
		ft_printf("[%d]", p->nb);
		p = p->next;
	}
	ft_printf("\n");
}

void	new_list(t_list2 *lst)
{
	if (lst == malloc(sizeof(t_list2)))
	{
		lst->len = 0;
		lst->head = NULL;
		lst->tail = NULL;
	}
}

void	free_list(t_list2 *lst)
{
	t_node *tmp;
	t_node *tmpnxt;

	tmp = lst->head;
	while (tmp != NULL)
	{
		tmpnxt = tmp->next;
		free(tmp);
		tmp = tmpnxt;
	}
}

void	free_final(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	free(p);
	free_list(lst_a);
	free_list(lst_b);
}
