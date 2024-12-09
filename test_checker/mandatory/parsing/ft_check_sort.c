/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:34:47 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/09 10:47:47 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int    ft_is_sort(t_stacks *stacks)
{
	int i;
	int j;
	long *sorted_stacks;

	sorted_stacks = sort_long_tab(stacks->a, stacks->size_a);
	if (!sorted_stacks)
		return (0);
	i = 0;
	j = 0;
	while (i < stacks->size_a)
	{
		if (sorted_stacks[i] == stacks->a[i])
			j++;
		i++;
	}
	free(sorted_stacks);
	if (i == j)
		return (0);
	return (1);
}