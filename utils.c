/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:25:24 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/30 16:42:25 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

t_stack	*max_node(t_list *list)
{
	int		max;
	t_stack	*temp;
	t_stack	*t_stack_max;

	temp = list->first;
	t_stack_max = list->first;
	max = temp->val;
	while (temp)
	{
		if (max < temp->val)
		{
			max = temp->val;
			t_stack_max = temp;
		}
		temp = temp->next;
	}
	return (t_stack_max);
}

t_stack	*min_node(t_list *list)
{
	int		min;
	t_stack	*temp;
	t_stack	*t_stack_min;

	temp = list->first;
	t_stack_min = list->first;
	min = temp->val;
	while (temp)
	{
		if (min > temp->val)
		{
			min = temp->val;
			t_stack_min = temp;
		}
		temp = temp->next;
	}
	return (t_stack_min);
}

int	med(t_list *list)
{
	int	med;

	med = 0;
	if (list_len(list) % 2 != 0)
		med = list_len(list) / 2 + 1;
	else if (list_len(list) == 2)
		med = 2;
	else
		med = list_len(list) / 2;
	return (med);
}
