/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:11:14 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/01 13:32:17 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./lib/libft/libft.h"
# include "./lib/ftprintf/ft_printf.h"
# include "./lib/gnl/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <limits.h>

typedef struct t_stack
{
	int				cost;
	int				val;
	int				index;
	struct t_stack	*target;
	struct t_stack	*next;
	struct t_stack	*prev;
}	t_stack;

typedef struct t_list
{
	int		len;
	t_stack	*first;
	t_stack	*last;
}	t_list;

//initialize.c
t_list	*init(void);
t_list	*add_end(t_list *list, int value);
int		list_len(t_list *list);
void	stack_index(t_list *list_a);

//swap_a_b.c
void	swap(t_list *list);
void	sa(t_list *list_a);
void	sb(t_list *list_b);
void	ss(t_list *list_a, t_list *list_b);

//push_a_b.c
void	push(t_list *list_src, t_list *list_dest);
void	pb(t_list *list_a, t_list *list_b);
void	pa(t_list *list_b, t_list *list_a);

//rotate_a_b.c
void	rotate(t_list *list);
void	ra(t_list *list_a);
void	rb(t_list *list_b);
void	rr(t_list *list_a, t_list *list_b);

//rev_rotate_a_b.c
void	reverse_rotate(t_list *list);
void	rra(t_list *list_a);
void	rrb(t_list *list_b);
void	rrr(t_list *list_a, t_list *list_b);

//main.c
void	create_list(t_list *list_a, int argc, char **argv);

//check_error.c
int		arg_is_num(int argc, char **argv);
int		arg_duplicate(int len, int *tab);
int		test_error( int argc, char **argv);

//tiny_liste.c
int		is_sorted(t_list *list_a);
void	tiny_sort(t_list *list_a);
void	sort_three(t_list *list_a);

//sort_a_b.c
void	algo_a_b(t_list *list_a, t_list *list_b);
void	find_target_b(t_list *list_a, t_list *list_b);
void	calcul_cost(t_list *list_a, t_list *list_b);
t_stack	*calcul_cheapest_cost(t_list *list_a, t_list *list_b);

//sort_b_a.c
void	algo_b_a(t_list *list_a, t_list *list_b);
void	find_target_a(t_list *list_a, t_stack *stack_b);

//move.c
void	move_up_ab(t_list *list_a, t_list *list_b, int idx_a, int idx_tar);
void	move_up(t_list *list, int idx_cheap_cost, char which_list);

//utils.c
long	ft_atol(const char *s);
void	ft_error(void);
t_stack	*max_node(t_list *list);
t_stack	*min_node(t_list *list);
int		med(t_list *list);

//free.c
void	free_list(t_list *stack);
void	free_argv(char **str);
void	the_rumbling(t_list	*list_a, t_list	*list_b, int argc, char **argv);

/**************************bonus**************************/

void	check_error(t_list *list_a, int argc, char **argv);
int		check_move(char *line, t_list *list_a, t_list *list_b);
void	get_move(t_list *list_a, t_list *list_b);

//swap_a_b.c
void	check_swap(t_list *list);
void	check_sa(t_list *list_a);
void	check_sb(t_list *list_b);
void	check_ss(t_list *list_a, t_list *list_b);

//push_a_b.c
void	check_push(t_list *list_src, t_list *list_dest);
void	check_pb(t_list *list_a, t_list *list_b);
void	check_pa(t_list *list_b, t_list *list_a);

//rotate_a_b.c
void	check_rotate(t_list *list);
void	check_ra(t_list *list_a);
void	check_rb(t_list *list_b);
void	check_rr(t_list *list_a, t_list *list_b);

//rev_rotate_a_b.c
void	check_reverse_rotate(t_list *list);
void	check_rra(t_list *list_a);
void	check_rrb(t_list *list_b);
void	check_rrr(t_list *list_a, t_list *list_b);

#endif