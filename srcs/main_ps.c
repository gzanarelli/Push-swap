/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_ps.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:16:38 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 09:53:18 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		main(int ac, char **av)
{
	t_list2 lst_a;
	t_list2 lst_b;
	t_param *p;

	if (ac == 1)
		return (0);
	ft_bzero(&lst_a, sizeof(t_list2));
	ft_bzero(&lst_b, sizeof(t_list2));
	if ((p = init_param()) == 0)
		return (0);
	p->print = 1;
	if ((check_pile(ac, av, &lst_a)) == KO)
	{
		free_final(&lst_a, &lst_b, p);
		return (write(2, "Error\n", 6));
	}
	push_check(av, &lst_a, &lst_b, p);
	free_final(&lst_a, &lst_b, p);
	return (0);
}
