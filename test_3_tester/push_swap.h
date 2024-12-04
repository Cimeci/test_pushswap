/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/11/20 23:38:46 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 23:38:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
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

int	ft_count_nb(char **str);
long	ft_atol(const char *nptr);

// ft_check.c //

int	ft_check_digit(char **argv);
int	ft_check_int(long *tab, int size);
int	ft_check_duplicate(long *tab, int size);

// main.c //

void	ft_puterror(char *str);

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

int	ft_search_min(t_stacks *stacks);
int	ft_search_max(t_stacks *stacks);

// ft_algo_ptt.c //

void	push_to_top_stack_a(long *stack, int index, int size);
void	push_to_top_stack_b(long *stack, int index, int size);

// ft_algo.c //

void	ft_algo(t_stacks *stacks);

#endif