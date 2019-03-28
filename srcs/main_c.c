/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_c.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 15:43:11 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 09:53:37 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	apply_bzero(t_list2 *lst_a, t_list2 *lst_b)
{
	ft_bzero(lst_a, sizeof(t_list2));
	ft_bzero(lst_b, sizeof(t_list2));
}

int			main(int ac, char **av)
{
	t_list2 lst_a;
	t_list2 lst_b;
	t_param *p;

	apply_bzero(&lst_a, &lst_b);
	if (ac == 1)
		return (0);
	if ((p = init_param()) == 0)
		return (0);
	if ((check_pile(ac, av, &lst_a)) == KO)
	{
		free_final(&lst_a, &lst_b, p);
		return (write(2, "Error\n", 6));
	}
	if (push_check(av, &lst_a, &lst_b, p))
	{
		free_final(&lst_a, &lst_b, p);
		return (0);
	}
	if ((check_order(&lst_a) == OK) && lst_b.len == 0)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_final(&lst_a, &lst_b, p);
	return (0);
}
