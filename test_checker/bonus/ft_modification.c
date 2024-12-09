/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifcation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:41:28 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 20:41:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	modification(t_moves *moves)
{
	moves->sa = "sa";
	moves->sb = "sb";
	moves->ss = "ss";
	moves->pa = "pa";
	moves->pb = "pb";
	moves->ra = "ra";
	moves->rb = "rb";
	moves->rr = "rr";
	moves->rra = "rra";
	moves->rrb = "rrb";
	moves->rrr = "rrr";
}

static void	apply_modif_double(char *line, t_stacks *stacks, t_moves *moves)
{
	if (ft_strcmp(line, moves->rr) == 0)
		rr_bonus(stacks);
	else if (ft_strcmp(line, moves->rrr) == 0)
		rrr_bonus(stacks);
	else if (ft_strcmp(line, moves->ss) == 0)
		ss_bonus(stacks);
}

static void	apply_modif_a(char *line, t_stacks *stacks, t_moves *moves)
{
	if(ft_strcmp(line, moves->ra))
		ra_bonus(stacks);
	else if (ft_strcmp(line, moves->rra))
		rra_bonus(stacks);
	else if (ft_strcmp(line, moves->sa))
		sa_bonus(stacks);
	else if (ft_strcmp(line, moves->pa))
		pa_bonus(stacks);
}
static void	apply_modif_b(char *line, t_stacks *stacks, t_moves *moves)
{
	if(ft_strcmp(line, moves->rb))
		rb_bonus(stacks);
	else if (ft_strcmp(line, moves->rrb))
		rrb_bonus(stacks);
	else if (ft_strcmp(line, moves->sb))
		sb_bonus(stacks);
	else if (ft_strcmp(line, moves->pb))
		pb_bonus(stacks);
}

#include <stdio.h>

int	apply_modification(char *line, t_stacks *stacks)
{
	t_moves	*moves;

	moves = malloc(sizeof(t_moves));
	if (!moves)
		return (0);
	modification(moves);
	if (!ft_check_information(line, moves))
	{
		free(moves);
		return (0);
	}
	apply_modif_a(line, stacks, moves);
	apply_modif_b(line, stacks, moves);
	int i = 0;
	while (i < stacks->size_a)
	{
		printf("%ld\n", stacks->a[i]);
		i++;
	}
	printf("\n");
	apply_modif_double(line, stacks, moves);
	free(moves);
	return (1);
}
