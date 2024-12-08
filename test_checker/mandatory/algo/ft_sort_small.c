/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:56:17 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/07 19:38:14 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stacks *stacks)
{
	if (stacks->a[0] > stacks->a[1])
		sa(stacks);
}

void	sort_three(t_stacks *stacks)
{
	if (stacks->a[0] > stacks->a[1] && stacks->a[1] < stacks->a[2]
		&& stacks->a[0] < stacks->a[2])
		sa(stacks);
	else if (stacks->a[0] > stacks->a[1] && stacks->a[1] > stacks->a[2])
	{
		sa(stacks);
		rra(stacks);
	}
	else if (stacks->a[0] > stacks->a[1] && stacks->a[1] < stacks->a[2])
		ra(stacks);
	else if (stacks->a[0] < stacks->a[1] && stacks->a[1] > stacks->a[2]
		&& stacks->a[0] < stacks->a[2])
	{
		sa(stacks);
		ra(stacks);
	}
	else if (stacks->a[0] < stacks->a[1] && stacks->a[1] > stacks->a[2])
		rra(stacks);
}
