/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_double_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:59:55 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/09 16:43:01 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rr_bonus(t_stacks *stacks)
{
	long	temp;
	int		i;

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
}

void	rrr_bonus(t_stacks *stacks)
{
	long	temp;
	int		i;

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
}

void	ss_bonus(t_stacks *stacks)
{
	long	temp;

	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
}
