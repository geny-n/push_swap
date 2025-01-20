/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:22:12 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/27 16:30:54 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_a(t_list *list_a, t_stack *stack_b)
{
	int		target;
	t_stack	*node_a;

	target = INT_MAX;
	node_a = list_a->first;
	while (node_a != NULL)
	{
		if (stack_b->val < node_a->val && node_a->val < target)
		{
			stack_b->target = node_a;
			target = node_a->val;
		}
		node_a = node_a->next;
	}
	if (target == INT_MAX)
		stack_b->target = min_node(list_a);
}

void	algo_b_a(t_list *list_a, t_list *list_b)
{
	int	i;

	i = list_len(list_b);
	while (i > 0)
	{
		find_target_a(list_a, list_b->first);
		move_up(list_a, list_b->first->target->index, 'a');
		pa(list_b, list_a);
		i--;
	}
	move_up(list_a, min_node(list_a)->index, 'a');
}
