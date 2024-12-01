/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:53:43 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/01 15:53:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(long *stack)
{
	long	temp;

	if (!stack)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	ft_printf("sa\n");
}

void	ra(long *stack, int size)
{
	long	temp;
	int		i;

	if (size < 2)
		return ;
	temp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
	ft_printf("ra\n");
}

void	rb(long *stack, int size)
{
	long	temp;
	int		i;

	if (size < 2)
		return ;
	temp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
	ft_printf("rb\n");
}

void	rra(long *stack, int size)
{
	long	temp;
	int		i;

	if (size < 2)
		return ;
	temp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
	ft_printf("rra\n");
}

void	pb(long *stack_a, long *stack_b, int *size_a, int *size_b)
{
	int	i;

	if (*size_a <= 0)
		return ;
	stack_b[*size_b] = stack_a[0];
	(*size_b)++;
	i = 0;
	while (i < *size_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	(*size_a)--;
	ft_printf("pb\n");
}

void	pa(long *stack_a, long *stack_b, int *size_a, int *size_b)
{
	int	i;

	if (*size_b <= 0)
		return ;
	i = *size_a;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[*size_b - 1];
	(*size_a)++;
	(*size_b)--;
	ft_printf("pa\n");
}
