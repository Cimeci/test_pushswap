/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:35:44 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/05 17:36:00 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void printf_stack(t_stacks *stacks)
{
	int i;
	i = 0;
	printf("\n");
	while (i < stacks->size_a)
		printf("%ld ", stacks->a[i++]);
	printf("| ");
	i = 0;
	while (i < stacks->size_b)
		printf("%ld ", stacks->b[i++]);
	printf("\n\n");
}