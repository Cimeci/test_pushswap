/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:58:15 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/07 19:38:18 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_start_b(t_stacks *stacks)
{
	if (stacks->size_a > 4)
		pb(stacks);
	pb(stacks);
}

static int	ft_search_target(t_stacks *stacks, int index_a)
{
	int	i;
	int	max;
	int	min;

	max = ft_search_max_for_b(stacks);
	min = ft_search_min_for_b(stacks);
	if (stacks->a[index_a] > stacks->b[max]
		|| stacks->a[index_a] < stacks->b[min])
		return (max);
	i = 0;
	while (i < stacks->size_b - 1)
	{
		if (stacks->a[index_a] < stacks->b[i]
			&& stacks->a[index_a] > stacks->b[i + 1])
			return (i + 1);
		i++;
	}
	return (0);
}

static int	count_operation(t_stacks *stacks, int index)
{
	int	count_a;
	int	count_b;
	int	target;

	if (index <= stacks->size_a / 2)
		count_a = index;
	else
		count_a = stacks->size_a - index;
	target = ft_search_target(stacks, index);
	if (target <= stacks->size_b / 2)
		count_b = target;
	else
		count_b = stacks->size_b - target;
	return (count_a + count_b);
}

static int	index_to_change(t_stacks *stacks)
{
	int	i;
	int	best_index;
	int	min_operations;
	int	current_operations;

	i = 0;
	best_index = 0;
	min_operations = count_operation(stacks, 0);
	while (i < stacks->size_a)
	{
		current_operations = count_operation(stacks, i);
		if (current_operations < min_operations)
		{
			best_index = i;
			min_operations = current_operations;
		}
		i++;
	}
	return (best_index);
}

void	ft_sort_a_to_b(t_stacks *stacks)
{
	int	index;
	int	target;

	while (stacks->size_a > 3)
	{
		index = index_to_change(stacks);
		target = ft_search_target(stacks, index);
		check_push_to_top(stacks, index, target);
		pb(stacks);
	}
	sort_three(stacks);
}
