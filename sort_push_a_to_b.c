/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:11:48 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/01 13:32:06 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_cost(t_list *l_a, t_list *l_b)
{
	int		len_a;
	int		len_b;
	t_stack	*a;
	int		idx;

	a = l_a->first;
	while (a)
	{
		idx = a->target->index;
		len_a = list_len(l_a) - a->index;
		len_b = list_len(l_b) - idx;
		if (a->index <= med(l_a) && idx <= med(l_b) && a->index <= idx)
			a->cost = idx - 1;
		else if (a->index <= med(l_a) && idx <= med(l_b) && a->index > idx)
			a->cost = a->index - 1;
		else if (a->index > med(l_a) && idx > med(l_b) && len_a <= len_b)
			a->cost = len_b + 1;
		else if (a->index > med(l_a) && idx > med(l_b) && len_a > len_b)
			a->cost = len_a + 1;
		else if (a->index <= med(l_a) && idx > med(l_b))
			a->cost = a->index - 1 + len_b + 1;
		else if (a->index > med(l_a) && idx <= med(l_b))
			a->cost = idx - 1 + len_a + 1;
		a = a->next;
	}
}

t_stack	*calcul_cheapest_cost(t_list *list_a, t_list *list_b)
{
	t_stack	*stack_a;
	int		temp;
	t_stack	*stack_temp;

	stack_a = list_a->first;
	stack_temp = list_a->first;
	calcul_cost(list_a, list_b);
	temp = stack_a->cost;
	while (stack_a)
	{
		if (temp > stack_a->cost)
		{
			temp = stack_a->cost;
			stack_temp = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (stack_temp);
}

void	find_target_b(t_list *list_a, t_list *list_b)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		target;

	node_a = list_a->first;
	while (node_a != NULL)
	{
		target = INT_MIN;
		node_b = list_b->first;
		while (node_b != NULL)
		{
			if (node_a->val > node_b->val && node_b->val > target)
			{
				node_a->target = node_b;
				target = node_b->val;
			}
			node_b = node_b->next;
		}
		if (target == INT_MIN)
			node_a->target = max_node(list_b);
		node_a = node_a->next;
	}
}

void	algo_a_b(t_list *list_a, t_list *list_b)
{
	t_stack	*stck_move;

	if (list_len(list_a) > 3)
		pb(list_a, list_b);
	if (list_len(list_a) > 3)
		pb(list_a, list_b);
	while (list_len(list_a) > 3)
	{
		find_target_b(list_a, list_b);
		stck_move = calcul_cheapest_cost(list_a, list_b);
		move_up_ab(list_a, list_b, stck_move->index, stck_move->target->index);
		move_up(list_a, stck_move->index, 'a');
		move_up(list_b, stck_move->target->index, 'b');
		pb(list_a, list_b);
	}
	sort_three(list_a);
	algo_b_a(list_a, list_b);
}
