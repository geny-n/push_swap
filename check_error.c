/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 01:28:16 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/01 13:31:45 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_is_num(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][0] == '-' || argv[i][0] == '+'))
			j++;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_limits(char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		if ((nb < -2147483648) || (nb > 2147483647))
			return (0);
		i++;
	}
	return (1);
}

int	arg_duplicate(int len, int *tab)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_duplicate_bis(char **argv)
{
	int	*tab;
	int	i;
	int	arg_dup;
	int	len;

	i = 0;
	len = 0;
	while (argv[len])
		len++;
	tab = (int *)malloc(sizeof(int) * len);
	while (argv[i])
	{
		tab[i] = ft_atol(argv[i]);
		i++;
	}
	arg_dup = arg_duplicate(len, tab);
	free(tab);
	return (arg_dup);
}

int	test_error( int argc, char **argv)
{
	int	arg_num;
	int	arg_lim;
	int	arg_dup;

	arg_num = arg_is_num(argc, argv);
	arg_lim = arg_limits(argv);
	if (argc == 2)
		arg_dup = arg_duplicate_bis(argv);
	else
		arg_dup = arg_duplicate_bis(argv + 1);
	if (arg_num == 0 || arg_lim == 0 || arg_dup == 0)
		return (-1);
	return (1);
}
