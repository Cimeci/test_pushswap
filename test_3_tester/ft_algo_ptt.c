/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_ptt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:32:12 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/06 18:31:12 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_top_stack_a(t_stacks *stacks, int index)
{
	int count;
	
	count = 0;
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

static int	count_push_to_top_stack_a(t_stacks *stacks, int index)
{
	int count;
	
	count = 0;
	if (index <= stacks->size_a / 2)
	{
		while (index-- > 0)
			count++;
		return (count);
	}
	else
	{
		while (index++ < stacks->size_a)
			count--;
		return (count);
	}
}	

static int	count_push_to_top_stack_b(t_stacks *stacks, int index)
{
	int count;
	
	count = 0;
	if (index <= stacks->size_b / 2)
	{
		while (index-- > 0)
			count++;
		return (count);
	}
	else
	{
		while (index++ < stacks->size_b)
			count--;
		return (count);
	}
}

static void    push_to_top_extension(t_stacks *stacks, t_count *count)
{
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

static void	push_to_top_stacks_negative(t_stacks *stacks, t_count *count)
{
	if (count->ptta > count->pttb)
	{
		count->count = count->pttb;
		count->ptta = count->ptta + (count->pttb * -1);
		count->pttb = 0;
	}	
	else
	{
		count->count = count->ptta;
		count->pttb = count->pttb + (count->ptta * -1);
		count->ptta = 0;
	}
	while (count->count < 0)
	{
		rrr(stacks);
		count->count++;
	}
}

static void	push_to_top_stacks_positive(t_stacks *stacks, t_count *count)
{
	if (count->ptta < count->pttb)
	{
		count->count = count->pttb;
		count->ptta = count->ptta - count->pttb;
		count->pttb = 0;
	}
	else
	{
		count->count = count->ptta;
		count->pttb = count->pttb - count->ptta;
		count->ptta = 0;
	}
	while (count->count > 0)
	{
		rr(stacks);
		count->count--;
	}
}

void    check_push_to_top(t_stacks *stacks, int index_a, int index_b)
{
	t_count *count;
	
	count = malloc(sizeof(t_count));
	count->ptta = count_push_to_top_stack_a(stacks, index_a);
	count->pttb = count_push_to_top_stack_b(stacks, index_b);
	if (count->pttb < 0 && count->ptta < 0)
		push_to_top_stacks_negative(stacks, count);
	else
		push_to_top_stacks_positive(stacks, count);
	push_to_top_extension(stacks, count);
	free(count);
}
