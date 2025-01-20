/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:38:12 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/01 14:13:58 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_swap(t_list *list)
{
	int	val;

	if (list->first == NULL || list->first->next == NULL)
		return ;
	val = list->first->val;
	list->first->val = list->first->next->val;
	list->first->next->val = val;
	stack_index(list);
}

void	check_sa(t_list *list_a)
{
	if (list_a->first == NULL)
		return ;
	check_swap(list_a);
}

void	check_sb(t_list *list_b)
{
	check_swap(list_b);
}

void	check_ss(t_list *list_a, t_list *list_b)
{
	check_swap(list_a);
	check_swap(list_b);
}
