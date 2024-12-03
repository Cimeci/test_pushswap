/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:52:56 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/03 18:23:05 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stacks
{
	int		size_a;
	int		size_b;
	long	*a;
	long	*b;
}			t_stacks;

#include "push_swap.h"

void	ft_start_b(t_stacks stacks)
{
	pb(stacks.a, stacks.b, stacks.size_a, stacks.size_b);
	pb(stacks.a, stacks.b, stacks.size_a, stacks.size_b);

	if (stacks.b[0] < stacks.b[1])
		sb(stacks.b);
}

int  count_operation(t_stacks stacks, int index)
{
	int i;
	int count;

	i = 0;
	count = 0;
// count le nombre de count dans la stack a //
	if (stacks.size_a - index > index)
		count = index;
	else if (stacks.size_a - index > index)
		count = stacks.size_a - index;

// count le nombre de count dans la stack b //
	while (stacks.a[index] > stacks.b[i])
	{
		i++;
		if (stacks.a[index] < stacks.b[i])
			break;
	}
	return (count + i);
}

int index_to_change(t_stacks stacks)
{
	int i;
	int index_result;
	int count;

	i = 0;
	index_result = 0;
	count = 0;
	while (i < stacks.size_a)
	{
		if (count < count_operation(stacks, i))
			index_result = i;
		count = count_operation(stacks, i);
		i++;
	}
	return (index_result);
}

int ft_search_close_to_index(t_stacks stacks, int index)
{
	long result;
	int i;

	i = 0;
	result = stacks.a[index];
	while (i < stacks.size_b)
	{
		if (result > stacks.b[i])
			break ;
		i++;
	}
	return (i);
}

void algo(t_stacks stacks)
{
	int index;
	int index_close;
	int i;
	
	ft_start_b(stacks);
	while (stacks.size_a > 3)
	{
		index = index_to_change(stacks);
		index_close = ft_search_close_to_index(stacks, index);
		push_to_top(stacks.a, index, stacks.size_a);
		push_to_top(stacks.b, index_close, stacks.size_b);
		pb(stacks.a, stacks.b, stacks.size_a, stacks.size_b);
	}
}
