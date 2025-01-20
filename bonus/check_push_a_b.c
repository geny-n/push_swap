/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:08:04 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/30 22:18:39 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*check_push_src(t_list *list_src)
{
	t_stack	*temp;

	temp = list_src->first;
	if (list_src->first->index < list_len(list_src))
	{
		list_src->first = list_src->first->next;
		list_src->first->prev = NULL;
	}
	else
	{
		list_src->first = NULL;
		list_src->last = NULL;
	}
	temp->prev = NULL;
	return (temp);
}

void	check_push(t_list *list_src, t_list *list_dest)
{
	t_stack	*temp;

	if (list_src->first == NULL)
		return ;
	temp = check_push_src(list_src);
	if (list_dest->first != NULL)
	{
		list_dest->first->prev = temp;
		temp->next = list_dest->first;
		list_dest->first = temp;
	}
	else
	{
		list_dest->first = temp;
		list_dest->last = temp;
		list_dest->first->next = NULL;
	}
}

void	check_pb(t_list *list_a, t_list *list_b)
{
	check_push(list_a, list_b);
	stack_index(list_a);
	stack_index(list_b);
}

void	check_pa(t_list *list_b, t_list *list_a)
{
	check_push(list_b, list_a);
	stack_index(list_a);
	stack_index(list_b);
}
