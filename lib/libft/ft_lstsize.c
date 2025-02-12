/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:22:07 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/20 13:28:35 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_liste *lst)
{
	int	i;

	i = 0;
	if (lst != NULL)
	{
		while (lst != NULL)
		{
			lst = lst -> next;
			i++;
		}
	}
	return (i);
}
