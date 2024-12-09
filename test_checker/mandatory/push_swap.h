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

# include "../lib/ft_printf/ft_printf.h"
# include <stdlib.h>

// struct //

typedef struct s_stacks
{
	int		size_a;
	int		size_b;
	long	*a;
	long	*b;
}			t_stacks;

typedef struct s_count
{
	int	pttb;
	int	ptta;
	int	count;
}		t_count;

// ft_split.c //

size_t	ft_count_word(const char *s, char c);
char	**ft_split(char const *s, char c);

/////////////////////////////
//        ft_tools.c       //
/////////////////////////////

long	*sort_long_tab(long *tab, int size);
int		ft_strcmp(const char *s1, const char *s2);

// ft_check_sort.c //

int    ft_is_sort(t_stacks *stacks);

// ft_check_tools.c //

int		ft_count_nb(char **str);
long	ft_atol(const char *nptr);

// ft_check.c //

int		ft_check_digit(char **argv);
int		ft_check_int(long *tab, int size);
int		ft_check_duplicate(long *tab, int size);
int		ft_check_after_sign(char **argv);

// ft_error.c //

void	ft_puterror(void);
void	ft_clean(t_stacks *stacks, int info);
void	ft_look_error(char **argv, t_stacks *stacks);

// ft_moves_a.c //

void	sa(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	pa(t_stacks *stacks);

// ft_moves_b.c //

void	sb(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	pb(t_stacks *stacks);

// ft_moves_satcks.c //

void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);
void	ss(t_stacks *stacks);

// ft_algo_tools.c //

int		ft_search_min_for_a(t_stacks *stacks);
int		ft_search_max_for_a(t_stacks *stacks);
int		ft_search_min_for_b(t_stacks *stacks);
int		ft_search_max_for_b(t_stacks *stacks);

// ft_algo_ptt.c //

void	push_to_top_stack_a(t_stacks *stacks, int index);
void	check_push_to_top(t_stacks *stacks, int index_a, int index_b);

// main.c // 

void	ft_init(t_stacks *stacks, char **argv);
long	*ft_tab(char **argv, int count_nb);

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

#endif