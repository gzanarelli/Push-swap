/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_big.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 12:24:06 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 13:28:42 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_b(t_list2 *lst_a, t_list2 *lst_b, t_param *p, int limit)
{
	int mid;

	mid = find_mid(lst_a, p);
	while (lst_b->len != limit)
	{
		if (H == 0)
			break ;
		apply_push(lst_a, lst_b, "pb", p);
		if (lst_b->len > 1 && HB < mid && p->nb_elem > 300)
			apply_rotate(lst_a, lst_b, "rb", p);
	}
}

void	ft_sort_a(t_list2 *lst_a, t_list2 *lst_b, t_param *p, int limit)
{
	int i;
	int cnt;
	int len;

	cnt = 0;
	i = -1;
	len = lst_a->len;
	while (++i < len)
	{
		if (cnt == p->first_limit)
			break ;
		if (H <= limit - 1 && H > p->first_limit - 1)
		{
			apply_push(lst_a, lst_b, "pb", p);
			cnt++;
			if (lst_b->len > 1)
				if (HB == HNB - 1)
					apply_swap(lst_a, lst_b, "sb", p);
		}
		else
			apply_rotate(lst_a, lst_b, "ra", p);
	}
	if (lst_a->len > p->first_limit)
		ft_sort_a(lst_a, lst_b, p, limit + p->first_limit);
}

void	sort_max(t_list2 *lst_a, t_list2 *lst_b, t_param *p)
{
	int limit;

	p->nb_elem = sort_quick(lst_a) - 1;
	limit = p->nb_elem / 10;
	p->first_limit = limit;
	start_sort(lst_a, lst_b, p, limit);
}

void	start_sort(t_list2 *lst_a, t_list2 *lst_b, t_param *p, int limit)
{
	int i;
	int cnt;

	cnt = 0;
	while (lst_a->len > limit)
		ft_sort_a(lst_a, lst_b, p, limit + p->first_limit);
	sort_ten_order(lst_a, lst_b, p);
	while (lst_b->len > limit)
		apply_push(lst_a, lst_b, "pa", p);
	sort_ten_reverse(lst_a, lst_b, p);
	while (check_order(lst_a) == KO)
	{
		i = -1;
		ft_sort_b(lst_a, lst_b, p, limit);
		while (check_order_reverse(lst_b) == KO)
			sort_ten_reverse(lst_a, lst_b, p);
		while (lst_b->len > 0)
			apply_push(lst_a, lst_b, "pa", p);
		while (++i < limit)
			apply_rotate(lst_a, lst_b, "ra", p);
		while (H == T + 1 && (cnt >= p->nb_elem / p->first_limit - 2))
			apply_rotate(lst_a, lst_b, "ra", p);
		cnt++;
	}
}
