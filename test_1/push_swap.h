/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:38:46 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 23:38:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "lib/ft_printf/ft_printf.h"

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

void	ft_puterror(char *str);

// ft_algo_tool.c //

void	sa(long *stack);
void	ra(long *stack, int size);
void	rb(long *stack, int size);
void	rra(long *stack, int size);
void	pb(long *stack_a, long *stack_b, int *size_a, int *size_b);
void	pa(long *stack_a, long *stack_b, int *size_a, int *size_b);

// ft_algo_search /

void	push_to_top(long *stack, int index, int size);

// ft_algo.c //

void	ft_algo(long *stack_a, int count_nb);

#endif