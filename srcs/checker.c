/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 17:52:55 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 10:00:48 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		check_doublon(t_list2 *lst)
{
	t_node *curr;
	t_node *next;

	curr = lst->head;
	next = lst->head->next;
	while (curr && next)
	{
		while (next)
		{
			if (curr->nb == next->nb)
				return (KO);
			else
				next = next->next;
		}
		curr = curr->next;
		next = curr->next;
	}
	return (OK);
}

int		check_fmt(char *str)
{
	int		i;

	i = 0;
	if ((ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX))
		return (KO);
	while (str[i])
	{
		if (i == 0)
			if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
				return (KO);
		if (i >= 1)
			if (!ft_isdigit(str[i]))
				return (KO);
		i++;
	}
	return (OK);
}

int		check_pile(int ac, char **av, t_list2 *lst)
{
	int		i;
	int		j;
	char	**tab;

	j = 1;
	if (ac == 1)
		j = 0;
	while (j < ac)
	{
		tab = ft_strsplit(av[j], ' ');
		i = -1;
		if (tab[i + 1] == 0)
			return (rtrn_err(tab));
		while (tab[++i])
		{
			if (check_fmt(tab[i]) == KO)
				return (rtrn_err(tab));
			add_element_end(lst, ft_atoi(tab[i]));
		}
		ft_free_2d(tab);
		j++;
	}
	return (check_doublon(lst));
}

int		check_order(t_list2 *lst)
{
	t_node *tmp;

	tmp = lst->head;
	if (tmp)
	{
		while (tmp && tmp->next)
		{
			if (tmp->nb >= tmp->next->nb)
				return (KO);
			else
				tmp = tmp->next;
		}
	}
	return (OK);
}

int		check_order_reverse(t_list2 *lst)
{
	t_node *tmp;

	tmp = lst->head;
	if (lst)
	{
		while (tmp && tmp->next)
		{
			if (tmp->nb <= tmp->next->nb)
				return (KO);
			else
				tmp = tmp->next;
		}
	}
	return (OK);
}
