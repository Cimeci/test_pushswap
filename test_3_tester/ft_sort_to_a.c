/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:58:50 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/06 18:24:31 by inowak--         ###   ########.fr       */
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

int		ft_search_target(t_stacks *stacks, int index_b)
{
	int i;
    int min;
    int max;
    
    min = ft_search_min_for_a(stacks);
    max = ft_search_max_for_a(stacks);
	i = 0;
    // printf("nb stacks_b : %ld\n", stacks->b[0]);
    if (stacks->b[index_b] > stacks->a[max])
        return (max + 1);
    if (stacks->b[index_b] < stacks->a[min])
        return (min);
    else 
    {
        // printf("v2\n");
        while (i < stacks->size_a - 1)
        {
	    	// printf("v2 : %ld\n", stacks->a[i]);
	    	// printf("v2 : %ld\n", stacks->a[i + 1]);
            if (stacks->b[index_b] > stacks->a[i] && stacks->b[index_b] < stacks->a[i + 1])
              return (i + 1);
		    i++;
        }
    }
    return (stacks->size_a);
}

void	ft_sort_b_to_a(t_stacks *stacks)
{
	int target;
	int index_b;

	target = 0;
	index_b = 0;
	while (stacks->size_b > 0)
	{
		// printf_stacks(stacks);
		target = ft_search_target(stacks, index_b);
		// printf("target : %d\n", target);
        // printf_stacks(stacks);
		push_to_top_stack_a(stacks, target);
		// printf_stacks(stacks);
		pa(stacks);
        // printf_stacks(stacks);
	}
}
