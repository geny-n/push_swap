/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:01:51 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/30 22:08:55 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init(void)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	if (list == NULL)
		exit(1);
	list->len = 0;
	list->first = NULL;
	list->last = NULL;
	return (list);
}

t_list	*add_end(t_list *list, int value)
{
	t_stack	*new_stack;

	new_stack = ft_calloc(1, sizeof(t_stack));
	if (new_stack == NULL)
		exit(1);
	new_stack->val = value;
	new_stack->next = NULL;
	if (list->first == NULL)
	{
		new_stack->prev = NULL;
		list->first = new_stack;
		list->last = new_stack;
	}
	else
	{
		list->last->next = new_stack;
		new_stack->prev = list->last;
		list->last = new_stack;
	}
	list->len++;
	return (list);
}

int	list_len(t_list *list)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = list->first;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	stack_index(t_list *list_a)
{
	int		i;
	t_stack	*temp;

	i = 0;
	if (list_a->first == NULL)
		return ;
	temp = list_a->first;
	while (temp != NULL)
	{
		i++;
		temp->index = i;
		temp = temp->next;
	}
}
