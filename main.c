/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:18:23 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/01 13:27:28 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(t_list *list_a, int argc, char **argv)
{
	int	nb;
	int	i;

	i = 0;
	if (test_error(argc, argv) == -1)
	{
		free_list(list_a);
		if (argc == 2)
			free_argv(argv);
		ft_error();
	}
	if (argc > 2)
		argv = argv + 1;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		add_end(list_a, nb);
		i++;
	}
	return ;
}

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
	create_list(list_a, argc, argv);
	list_b = init();
	if (is_sorted(list_a))
	{
		the_rumbling(list_a, list_b, argc, argv);
		return (0);
	}
	if (list_a->len <= 3)
		tiny_sort(list_a);
	else
		algo_a_b(list_a, list_b);
	the_rumbling(list_a, list_b, argc, argv);
	return (0);
}
