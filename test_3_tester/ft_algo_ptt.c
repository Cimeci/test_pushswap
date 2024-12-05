/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_ptt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:32:12 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/05 12:56:56 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_top_stack_a(t_stacks *stacks, int index)
{
	if (index <= stacks->size_a / 2)
	{
		while (index-- > 0)
			ra(stacks);
	}
	else
	{
		while (index++ < stacks->size_a)
			rra(stacks);
	}
}

void	push_to_top_stack_b(t_stacks *stacks, int index)
{
	if (index <= stacks->size_b / 2)
	{
		while (index-- > 0)
			rb(stacks);
	}
	else
	{
		while (index++ < stacks->size_b)
			rrb(stacks);
	}
}
