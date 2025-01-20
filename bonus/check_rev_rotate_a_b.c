/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rev_rotate_a_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:45 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/01 14:16:15 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_reverse_rotate(t_list *list)
{
	t_stack	*stack_temp;
	t_stack	*stack_first;

	if (list->first == NULL || list->first->next == NULL)
		return ;
	stack_temp = list->last;
	stack_first = list->first;
	list->last = list->last->prev;
	list->last->next = NULL;
	list->first = stack_temp;
	list->first->next = stack_first;
	list->first->next->prev = list->first;
	list->first->prev = NULL;
	stack_index(list);
}

void	check_rra(t_list *list_a)
{
	check_reverse_rotate(list_a);
}

void	check_rrb(t_list *list_b)
{
	check_reverse_rotate(list_b);
}

void	check_rrr(t_list *list_a, t_list *list_b)
{
	check_reverse_rotate(list_a);
	check_reverse_rotate(list_b);
}
