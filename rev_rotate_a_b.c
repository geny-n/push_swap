/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:45 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/26 22:46:07 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list *list)
{
	t_stack	*stack_temp;
	t_stack	*stack_first;

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

void	rra(t_list *list_a)
{
	reverse_rotate(list_a);
	ft_printf ("rra\n");
}

void	rrb(t_list *list_b)
{
	reverse_rotate(list_b);
	ft_printf ("rrb\n");
}

void	rrr(t_list *list_a, t_list *list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_printf ("rrr\n");
}
