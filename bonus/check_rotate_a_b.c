/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate_a_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:22:30 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/01 14:16:36 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_rotate(t_list *list)
{
	int		temp;
	t_stack	*temp_stack;

	if (list->first == NULL || list->first->next == NULL)
		return ;
	temp = 0;
	temp = list->first->val;
	temp_stack = list->first->next;
	add_end(list, temp);
	free(list->first);
	list->first = temp_stack;
	list->first->prev = NULL;
	stack_index(list);
}

void	check_ra(t_list *list_a)
{
	check_rotate(list_a);
}

void	check_rb(t_list *list_b)
{
	check_rotate(list_b);
}

void	check_rr(t_list *list_a, t_list *list_b)
{
	check_rotate(list_a);
	check_rotate(list_b);
}
