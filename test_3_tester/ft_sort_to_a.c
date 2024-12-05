/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:58:50 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/05 19:31:58 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_btw_max_and_min(t_stacks *stacks)
{
	int min;
	int max;
	int i;
	int count;

	i = 0;
	count = 0;
	min = ft_search_min_for_a(stacks);
	max = ft_search_max_for_a(stacks);
	// printf("min : %ld | max : %ld\n", stacks->a[min], stacks->a[max]);
	while (i < stacks->size_b)
	{
		// printf("stack->b[%d] : %ld\n", i ,stacks->b[i]);
		if (stacks->b[i] < stacks->a[max] && stacks->b[i] > stacks->a[min])
		{
			// printf("count :[%d] : %ld\n", i ,stacks->b[i]);
			count++;
		}
		i++;
	}
	return (count);
}

int		ft_search_target(t_stacks *stacks, int index_b);

#include <stdio.h>

void	ft_sort_b_to_a(t_stacks *stacks)
{
	int min;
	int max;
	int btw_count;
	int target;

	target = 0;
	btw_count = ft_count_btw_max_and_min(stacks);
	while (stacks->size_b - btw_count > 0)
	{
		btw_count = ft_count_btw_max_and_min(stacks);
		// printf("btw_count : %d\n", btw_count);
		min = ft_search_min_for_a(stacks);
		max = ft_search_max_for_a(stacks);
		// printf("stack->[0] : %ld\n", stacks->b[0]);
		if (stacks->b[0] < stacks->a[min] || stacks->b[0] > stacks->a[max])
		{
			// printf_stack(stacks);
			push_to_top_stack_a(stacks, min);
			// printf_stack(stacks);
			pa(stacks);
			// printf_stack(stacks);
		}
		else if (stacks->b[0] < stacks->a[max] && stacks->b[0] > stacks->a[min])
		{
			int safety = 0; 
			while (stacks->b[0] < stacks->a[max] && stacks->b[0] > stacks->a[min])
			{
				rb(stacks);
				safety++;
				if (safety > stacks->size_b)
					exit(0);
			}
		}
	}
	while (stacks->size_b > 0)
	{
		// printf_stack(stacks);
		target = ft_search_target(stacks, 0);
		// printf("target : %d\n", target);
		push_to_top_stack_a(stacks, target);
		// printf_stack(stacks);
		pa(stacks);
	}
}

int		ft_search_target(t_stacks *stacks, int index_b)
{
	int i;

	i = 0;
	// printf("INDEX : %ld\n", stacks->b[index_b]);
    if (stacks->b[index_b] < stacks->a[0] && stacks->b[index_b] > stacks->a[stacks->size_a])
        	return (0);
	// printf("size_a : %d\n", stacks->size_a);
    while (i < stacks->size_a - 1)
    {
		// printf("stack->a[%d] : %ld\n", i, stacks->a[i]);
		// printf("stack->a[%d + 1] : %ld\n", i, stacks->a[i + 1]);
        if (stacks->b[index_b] > stacks->a[i] && stacks->b[index_b] < stacks->a[i + 1])
            return (i + 1);
		i++;
    }
	return (stacks->size_a);
}