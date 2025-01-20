/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:08:04 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/26 22:54:33 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push_src(t_list *list_src)
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

void	push(t_list *list_src, t_list *list_dest)
{
	t_stack	*temp;

	temp = push_src(list_src);
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

void	pb(t_list *list_a, t_list *list_b)
{
	push(list_a, list_b);
	ft_printf ("pb\n");
	stack_index(list_a);
	stack_index(list_b);
}

void	pa(t_list *list_b, t_list *list_a)
{
	push(list_b, list_a);
	ft_printf ("pa\n");
	stack_index(list_a);
	stack_index(list_b);
}
