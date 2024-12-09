/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:21:36 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/09 10:50:12 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clean(t_stacks *stacks, int info)
{
	if (stacks->b)
		free(stacks->b);
	if (stacks->a)
		free(stacks->a);
	if (stacks)
		free(stacks);
	if (info == 1)
		ft_puterror();
	exit(0);
}

void	ft_puterror(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_look_error(char **argv, t_stacks *stacks)
{
	if (!ft_check_digit(argv) || !ft_check_after_sign(argv))
		ft_clean(stacks, 1);
	if (!(ft_check_duplicate(stacks->a, stacks->size_a)))
		ft_clean(stacks, 1);
	if (!(ft_check_int(stacks->a, stacks->size_a)))
		ft_clean(stacks, 1);
	if (!stacks->a || !stacks->b)
		ft_clean(stacks, 1);
}
