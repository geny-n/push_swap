/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:38:12 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/26 22:45:31 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *list)
{
	int	val;

	if (list->first == NULL || list->first->next == NULL)
		return ;
	val = list->first->val;
	list->first->val = list->first->next->val;
	list->first->next->val = val;
	stack_index(list);
}

void	sa(t_list *list_a)
{
	swap(list_a);
	ft_printf ("sa\n");
}

void	sb(t_list *list_b)
{
	swap(list_b);
	ft_printf ("sb\n");
}

void	ss(t_list *list_a, t_list *list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf ("ss\n");
}
