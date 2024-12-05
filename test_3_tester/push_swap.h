/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:22:06 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/05 17:22:06 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/ft_printf/ft_printf.h"
# include <limits.h>
// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// struct //

typedef struct s_stacks
{
	int size_a;
	int size_b;
	long *a;
	long *b;
} t_stacks;

// ft_split.c //

size_t	ft_count_word(const char *s, char c);
char	**ft_split(char const *s, char c);

// ft_check_tools.c //

int		ft_count_nb(char **str);
long	ft_atol(const char *nptr);

// ft_check.c //

int		ft_check_digit(char **argv);
int		ft_check_int(long *tab, int size);
int		ft_check_duplicate(long *tab, int size);

// main.c //

void	ft_puterror(t_stacks *stacks);

// ft_algo_moves_a.c //

void	sa(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	pa(t_stacks *stacks);

// ft_algo_moves_b.c //

void	sb(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	pb(t_stacks *stacks);

// ft_algo_tools.c //

int		ft_search_min_for_a(t_stacks *stacks);
int		ft_search_max_for_a(t_stacks *stacks);
int		ft_search_min_for_b(t_stacks *stacks);
int		ft_search_max_for_b(t_stacks *stacks);

// ft_algo_ptt.c //

void	push_to_top_stack_a(t_stacks *stacks, int index);
void	push_to_top_stack_b(t_stacks *stacks, int index);

// ft_algo.c //

int		is_sorted(t_stacks *stacks);
void	ft_algo(t_stacks *stacks);

// ft_sort_to_a.c

void	ft_sort_b_to_a(t_stacks *stacks);

// ft_sort_to_b.c

void	ft_start_b(t_stacks *stacks);
void	ft_sort_a_to_b(t_stacks *stacks);

// ft_sort_small.c //

void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);


/// ft_print_stacks.c ///

void printf_stack(t_stacks *stacks);


#endif