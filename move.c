/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:00:51 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/01 13:28:27 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_up_ab(t_list *list_a, t_list *list_b, int idx_a, int idx_tar)
{
	int	i;
	int	med_a;
	int	med_b;
	int	len_a;
	int	len_b;

	i = 0;
	med_a = med(list_a);
	med_b = med(list_b);
	len_a = list_len(list_a) - idx_a;
	len_b = list_len(list_b) - idx_tar;
	if (idx_a <= med_a && idx_tar <= med_b && idx_a <= idx_tar)
		while (i++ != idx_a - 1)
			rr (list_a, list_b);
	else if (idx_a <= med_a && idx_tar <= med_b && idx_a > idx_tar)
		while (i++ != idx_tar - 1)
			rr (list_a, list_b);
	else if (idx_a > med_a && idx_tar > med_b && len_a <= len_b)
		while (i++ != len_a + 1)
			rrr (list_a, list_b);
	else if (idx_a > med_a && idx_tar > med_b && len_a > len_b)
		while (i++ != len_b + 1)
			rrr (list_a, list_b);
}

void	move_up(t_list *list, int idx_cheap_cost, char which_list)
{
	int	i;
	int	mediane;

	i = 0;
	mediane = med(list);
	if (idx_cheap_cost <= mediane)
	{
		while (i++ != idx_cheap_cost - 1)
		{
			if (which_list == 'a')
				ra(list);
			else
				rb(list);
		}
	}
	else
	{
		while (i++ != list_len(list) - idx_cheap_cost + 1)
		{
			if (which_list == 'a')
				rra(list);
			else
				rrb(list);
		}
	}
}
