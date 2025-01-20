/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:07:39 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/01 13:20:51 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == 0)
			return (0);
	}
	list_a = init();
	check_error(list_a, argc, argv);
	list_b = init();
	get_move(list_a, list_b);
	the_rumbling(list_a, list_b, argc, argv);
	return (0);
}
