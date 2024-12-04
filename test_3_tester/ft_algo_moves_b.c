/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_moves_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:02:18 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/04 15:19:34 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stacks *stacks)
{
	long	temp;

	if (!stacks->b)
		return ;
	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
	ft_printf("sb\n");
}

void	rb(t_stacks *stacks)
{
	long	temp;
	int		i;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[stacks->size_b - 1] = temp;
	ft_printf("rb\n");
}

void	rrb(t_stacks *stacks)
{
	long	temp;
	int		i;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = temp;
	ft_printf("rrb\n");
}

void	pb(t_stacks *stacks)
{
	int	i;

	if (stacks->size_a <= 0)
		return ;
	stacks->b[stacks->size_b] = stacks->a[0];
	stacks->size_b++;
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	(stacks->size_a)--;
	ft_printf("pb\n");
}