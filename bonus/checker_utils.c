/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:07:11 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/02 17:24:19 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_move(char *line, t_list *list_a, t_list *list_b)
{
	if (ft_strncmp(line, "pb\n", 3) == 0)
		check_pb(list_a, list_b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		check_pa(list_b, list_a);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		check_rra(list_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		check_rrb(list_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		check_rrr(list_a, list_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		check_ra(list_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		check_rb(list_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		check_rr(list_a, list_b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		check_sa(list_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		check_sb(list_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		check_ss(list_a, list_b);
	else
		return (1);
	return (0);
}

void	get_move(t_list *list_a, t_list *list_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (check_move(line, list_a, list_b))
		{
			get_next_line(-42);
			ft_printf ("Error\n");
			free (line);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
	free (line);
	if (is_sorted(list_a) && list_b->first == NULL)
		ft_printf("OK\n");
	else
		ft_printf ("KO\n");
}

void	check_error(t_list *list_a, int argc, char **argv)
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
