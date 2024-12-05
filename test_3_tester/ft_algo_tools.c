/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:53:43 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/05 13:46:43 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_min_for_a(t_stacks *stacks)
{
	int 	index;
	int 	i;
	long 	min;

	index = 0;
	i = 0;
	min = stacks->a[0];
	while (i < stacks->size_a)
	{
		// printf("MIN : stack_a[%d] = %ld\n", i, stacks->a[i]);
		if (min > stacks->a[i])
		{
			min = stacks->a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	ft_search_max_for_a(t_stacks *stacks)
{
	int		index;
	int		i;
	long	max;

	index = 0;
	i = 0;
	max = stacks->a[0];
	while (i < stacks->size_a)
	{
		// printf("MAX : stack_a[%d] = %ld\n", i, stacks->a[i]);
		if (max < stacks->a[i])
		{
			max = stacks->a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	ft_search_min_for_b(t_stacks *stacks)
{
	int 	index;
	int 	i;
	long 	min;

	index = 0;
	i = 0;
	min = stacks->b[0];
	while (i < stacks->size_b)
	{
		// printf("MIN : stack_b[%d] = %ld\n", i, stacks->b[i]);
		if (min > stacks->b[i])
		{
			min = stacks->b[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	ft_search_max_for_b(t_stacks *stacks)
{
	int		index;
	int		i;
	long	max;

	index = 0;
	i = 0;
	max = stacks->b[0];
	while (i < stacks->size_b)
	{
		// printf("MAX : stack_b[%d] = %ld\n", i, stacks->b[i]);
		if (max < stacks->b[i])
		{
			max = stacks->b[i];
			index = i;
		}
		i++;
	}
	return (index);
}
