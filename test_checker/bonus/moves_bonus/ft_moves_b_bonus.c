/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_b_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:02:18 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/08 18:04:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	sb_bonus(t_stacks *stacks)
{
	long	temp;

	if (!stacks->b)
		return ;
	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
}

void	rb_bonus(t_stacks *stacks)
{
	long	temp;
	int		i;

	if (!stacks || !stacks->b || stacks->size_b < 2)
		exit(0);
	temp = stacks->b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[stacks->size_b - 1] = temp;
}

void	rrb_bonus(t_stacks *stacks)
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
}

void	pb_bonus(t_stacks *stacks)
{
	int	i;

	if (stacks->size_a <= 0)
		return ;
	stacks->size_b++;
	i = stacks->size_b;
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = stacks->a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	(stacks->size_a)--;
}
