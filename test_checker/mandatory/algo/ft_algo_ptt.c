/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_ptt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:32:12 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/07 19:38:01 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static int	count_push_to_top(int size, int index)
{
	int	count;

	count = 0;
	if (index <= size / 2)
	{
		while (index-- > 0)
			count++;
	}
	else
	{
		while (index++ < size)
			count--;
	}
	return (count);
}

static void	apply_double_rotations(t_stacks *stacks, t_count *count)
{
	while (count->ptta > 0 && count->pttb > 0)
	{
		rr(stacks);
		count->ptta--;
		count->pttb--;
	}
	while (count->ptta < 0 && count->pttb < 0)
	{
		rrr(stacks);
		count->ptta++;
		count->pttb++;
	}
}

static void	apply_rotations(t_stacks *stacks, t_count *count)
{
	apply_double_rotations(stacks, count);
	while (count->ptta > 0)
	{
		ra(stacks);
		count->ptta--;
	}
	while (count->pttb > 0)
	{
		rb(stacks);
		count->pttb--;
	}
	while (count->ptta < 0)
	{
		rra(stacks);
		count->ptta++;
	}
	while (count->pttb < 0)
	{
		rrb(stacks);
		count->pttb++;
	}
}

void	check_push_to_top(t_stacks *stacks, int index_a, int index_b)
{
	t_count	count;

	count.ptta = count_push_to_top(stacks->size_a, index_a);
	count.pttb = count_push_to_top(stacks->size_b, index_b);
	apply_rotations(stacks, &count);
}
