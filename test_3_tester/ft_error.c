/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:21:36 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/07 09:27:43 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean(t_stacks *stacks)
{
	if (stacks->b)
		free(stacks->b);
	if (stacks->a)
		free(stacks->a);
	if (stacks)
		free(stacks);
	ft_puterror();
}

void	ft_puterror()
{
    write(2, "Error\n", 6);
    exit(0);
}

void	ft_look_error(char **argv, t_stacks *stacks)
{
	ft_check_after_sign(argv);
	if (!ft_check_digit(argv))
		ft_clean(stacks);
	ft_check_duplicate(stacks->a, stacks->size_a);
	ft_check_int(stacks->a, stacks->size_a);
	if (!stacks->a  || !stacks->b)
		ft_clean(stacks);
}