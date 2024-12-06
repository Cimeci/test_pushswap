/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:52:56 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/06 18:25:45 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_algo(t_stacks *stacks)
{
	printf_stack(stacks);
	if (stacks->size_a == 2)
		sort_two(stacks);
	if (stacks->size_a == 3)
		sort_three(stacks);
	if (stacks->size_a > 3)
	{
		ft_start_b(stacks);
		ft_sort_a_to_b(stacks);
		ft_sort_b_to_a(stacks);
		push_to_top_stack_a(stacks, ft_search_min_for_a(stacks));
	}
	printf_stack(stacks);
}
