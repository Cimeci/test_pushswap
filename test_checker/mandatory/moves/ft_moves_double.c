/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:59:55 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/08 20:21:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stacks *stacks)
{
	long	temp;
	int		i;

	if (stacks->size_b < 2 || stacks->size_a < 2)
		exit(0);
	temp = stacks->b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[stacks->size_b - 1] = temp;
	temp = stacks->a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[stacks->size_a - 1] = temp;
	ft_printf("rr\n");
}

void	rrr(t_stacks *stacks)
{
	long	temp;
	int		i;

	if (stacks->size_b < 2 || stacks->size_a < 2)
		return ;
	temp = stacks->b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = temp;
	temp = stacks->a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = temp;
	ft_printf("rrr\n");
}

void	ss(t_stacks *stacks)
{
	long	temp;

	if (!stacks->a || !stacks->b)
		return ;
	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
	ft_printf("ss\n");
}
