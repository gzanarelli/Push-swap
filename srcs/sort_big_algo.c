/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_big_algo.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 13:28:02 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 13:50:54 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		num_max(t_list2 *lst)
{
	t_node *tmp;
	t_node *head;

	tmp = lst->head;
	head = lst->head;
	while (head)
	{
		if (tmp->nb < head->nb)
			tmp = head;
		head = head->next;
	}
	return (tmp->nb);
}

void	sort_ten_order(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	int		min;
	t_node	*tmp;
	int		elem;

	elem = sort_quick(lst_a);
	tmp = lst_a->head;
	while (tmp && lst_a->head->next)
	{
		tmp = lst_a->head;
		min = num_min(lst_a);
		if (check_order(lst_a) == OK)
			break ;
		if (lst_a->len == 2)
			if (lst_a->head->nb > lst_a->tail->nb)
				apply_swap(lst_a, lst_b, "sa", p);
		if (lst_a->len == 3)
		{
			list_trois(tmp, lst_a, lst_b, p);
			break ;
		}
		if (lst_a->len > 3)
			sort_bubble(lst_a, lst_b, min, p);
	}
	while (lst_a->len < 10)
		apply_push(lst_a, lst_b, "pa", p);
}

void	sort_ten_reverse(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	t_node	*head;
	int		i;
	int		max;

	max = num_max(lst_b);
	i = 0;
	head = lst_b->head;
	while (head)
	{
		if (head->nb == max)
		{
			if (i <= lst_b->len / 2)
				while (i--)
					apply_rotate(lst_a, lst_b, "rb", p);
			else
				while (i++ < lst_b->len)
					apply_reverse(lst_a, lst_b, "rrb", p);
			apply_push(lst_a, lst_b, "pa", p);
			break ;
		}
		head = head->next;
		i++;
	}
}

int		find_mid(t_list2 *lst_a, t_param *p)
{
	int		mid;
	t_node	*tmp;
	int		limit;

	limit = p->first_limit;
	mid = 0;
	tmp = lst_a->head;
	while (limit--)
	{
		mid = mid + tmp->id;
		tmp = tmp->next;
	}
	mid = mid / p->first_limit;
	return (mid);
}
