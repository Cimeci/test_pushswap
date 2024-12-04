/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:52:56 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/04 15:56:31 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_start_b(t_stacks *stacks)
{
	pb(stacks);
	pb(stacks);
}

int  count_operation(t_stacks *stacks, int index)
{
	int i;
	int count;

	i = 0;
	count = 0;
// count le nombre de count dans la stack a //
	if (stacks->size_a - index > index)
		count = index;
	else
		count = stacks->size_a - index;

// count le nombre de count dans la stack b //
	while (i < stacks->size_b)
	{
		i++;
		if (stacks->a[index] < stacks->b[i])
			break;
	}
	return (count + i);
}

int index_to_change(t_stacks *stacks)
{
	int i;
	int index_result;
	int count;
	int tmp_count;

	i = 0;
	index_result = 0;
	count = 0;
	while (i < stacks->size_a - 1)
	{
		tmp_count = count_operation(stacks, i);
		if (count < tmp_count)
		{
			index_result = i;
			count = tmp_count;
		}
		i++;
	}
	return (index_result);
}

int  ft_search_target(t_stacks *stacks, int index)
{
	int i;
	int max;
	int min;

	max = ft_search_max(stacks);
	min = ft_search_min(stacks);
	printf("max : %d | min : %d\n", max, min);
	i = max;
	if (stacks->a[index] >= stacks->b[max] || stacks->a[index] < stacks->b[min])
	{
		i = max;
		while (i < stacks->size_a - 1)
		{
			if (stacks->a[index] < stacks->b[i]	&& stacks->a[index] >= stacks->b[i + 1])
				return (i);
			i++;
		}
		i = 0;
		while (i < max - 1)
		{
			if (stacks->a[index] < stacks->b[i]	&& stacks->a[index] >= stacks->b[i + 1])
				return (i);
			i++;
		}	
	}
	return (0);
}

#include <stdio.h>

void ft_algo(t_stacks *stacks)
{
	int index;
	int target;
	int i;
	
	if (stacks->size_a == 3)
	{
		ft_printf("algo sort 3\n");
		exit(0);
	}
	i = 0;
	while (i < stacks->size_a)
		printf("%ld ", stacks->a[i++]);
	i = 0;
	printf("| ");
	while (i < stacks->size_b)
		printf("%ld ", stacks->b[i++]);
	printf("\n");
	if (stacks->size_a > 3)
	{
		if (stacks->size_a > 5)
			ft_start_b(stacks);
		printf("size_a : %d \n", stacks->size_a);
		printf("size_b : %d \n", stacks->size_b);
		while (stacks->size_a > 3)
		{
			i = 0;
			while (i < stacks->size_a)
				printf("%ld ", stacks->a[i++]);
			i = 0;
			printf("| ");
			while (i < stacks->size_b)
				printf("%ld ", stacks->b[i++]);
			printf("\n");
			index = index_to_change(stacks);
			printf("index : %d \n", index);

			target = ft_search_target(stacks, index);
			printf("index target : %d \n", target);
			
			push_to_top_stack_a(stacks->a, index, stacks->size_a);

			push_to_top_stack_b(stacks->b, target, stacks->size_b);

			pb(stacks);
		}
	}
	i = 0;
	while (i < stacks->size_a)
		printf("%ld ", stacks->a[i++]);
	i = 0;
	printf("| ");
	while (i < stacks->size_b)
		printf("%ld ", stacks->b[i++]);
	printf("\n");
}
