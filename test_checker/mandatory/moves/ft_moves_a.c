/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_moves_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:00:39 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/07 19:37:53 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stacks *stacks)
{
	long	temp;

	if (!stacks->a)
		return ;
	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
	ft_printf("sa\n");
}

void	ra(t_stacks *stacks)
{
	long	temp;
	int		i;

	if (stacks->size_a < 2)
		return ;
	temp = stacks->a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[stacks->size_a - 1] = temp;
	ft_printf("ra\n");
}

void	rra(t_stacks *stacks)
{
	long	temp;
	int		i;

	if (stacks->size_a < 2)
		return ;
	temp = stacks->a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = temp;
	ft_printf("rra\n");
}

void	pa(t_stacks *stacks)
{
	int	i;

	if (stacks->size_b <= 0)
		return ;
	stacks->size_a++;
	i = stacks->size_a;
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = stacks->b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	(stacks->size_b)--;
	ft_printf("pa\n");
}
