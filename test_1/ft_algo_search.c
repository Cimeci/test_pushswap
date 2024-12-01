/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:32:12 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/26 18:37:16 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_extension(long *stack, int index, int size)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	while (i < index)
	{
		temp = stack[0];
		j = 0;
		while (j < size - 1)
		{
			stack[j] = stack[j + 1];
			j++;
		}
		stack[size - 1] = temp;
		ft_printf("ra\n");
		i++;
	}
}

static void	end_extension(long *stack, int index, int size)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	while (i < size - index)
	{
		temp = stack[size - 1];
		j = size - 1;
		while (j > 0)
		{
			stack[j] = stack[j - 1];
			j--;
		}
		stack[0] = temp;
		ft_printf("rra\n");
		i++;
	}
}

void	push_to_top(long *stack, int index, int size)
{
	if (index <= size / 2)
		start_extension(stack, index, size);
	else
		end_extension(stack, index, size);
}
