/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:59:38 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/02 15:22:17 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_stack	*temp;

	temp = list->first;
	while (temp->next)
	{
		if (temp->val > temp->next->val)
			return (0);
		else
			temp = temp->next;
	}
	return (1);
}

void	tiny_sort(t_list *list_a)
{
	if (list_a->len == 2)
		sa(list_a);
	if (list_a->len == 3)
		sort_three(list_a);
}

void	sort_three(t_list *list_a)
{
	int	max;

	max = max_node(list_a)->val;
	if (list_a->first->val == max)
		ra(list_a);
	else if (list_a->first->next->val == max)
		rra(list_a);
	if (list_a->first->val > list_a->first->next->val)
		sa(list_a);
}
