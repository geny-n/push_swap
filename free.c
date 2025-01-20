/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:47:44 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/27 16:01:12 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *list)
{
	t_stack	*temp;
	t_stack	*del;

	if (list != NULL)
	{
		temp = list->first;
		while (temp != NULL)
		{
			del = temp;
			temp = temp->next;
			free(del);
		}
		free(list);
		list = NULL;
	}
}

void	free_argv(char **str)
{
	int	i;

	i = 1;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(*(str + i));
		i--;
	}
	free(str);
}

void	the_rumbling(t_list	*list_a, t_list	*list_b, int argc, char **argv)
{
	free_list(list_a);
	free_list(list_b);
	if (argc == 2)
		free_argv(argv);
}
