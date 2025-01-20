/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:22:30 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/22 17:36:19 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list *list)
{
	int		temp;
	t_stack	*temp_stack;

	temp = 0;
	temp = list->first->val;
	temp_stack = list->first->next;
	add_end(list, temp);
	free(list->first);
	list->first = temp_stack;
	list->first->prev = NULL;
	stack_index(list);
}

void	ra(t_list *list_a)
{
	rotate(list_a);
	ft_printf ("ra\n");
}

void	rb(t_list *list_b)
{
	rotate(list_b);
	ft_printf ("rb\n");
}

void	rr(t_list *list_a, t_list *list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf ("rr\n");
}
