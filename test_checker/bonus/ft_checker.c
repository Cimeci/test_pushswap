/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:03:56 by marvin            #+#    #+#             */
/*   Updated: 2024/12/07 23:03:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*ft_sup_endl(char *line)
{
	char	*tab;
	int		i;

	if (!line)
		return (NULL);
	tab = malloc(sizeof(char) * ft_strlen(line));
	if (!tab)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		tab[i] = line[i];
		i++;
	}
	tab[i] = '\0';
	free(line);
	return (tab);
}

int	ft_check_information(char *line, t_moves *moves)
{
	int count;

	count = 0;
	if (ft_strcmp(line, moves->sa) == 0 
		|| ft_strcmp(line, moves->sb) == 0)
		count++;
	if (ft_strcmp(line, moves->ss) == 0)
		count++;
	if (ft_strcmp(line, moves->pa) == 0 
		|| ft_strcmp(line, moves->pb) == 0)
		count++;
	if (ft_strcmp(line, moves->ra) == 0 
		|| ft_strcmp(line, moves->rb) == 0)
		count++;
	if (ft_strcmp(line, moves->rr) == 0)
		count++;
	if (ft_strcmp(line, moves->rra) == 0 
		|| ft_strcmp(line, moves->rrb) == 0)
		count++;
	if (ft_strcmp(line, moves->rrr) == 0)
		count++;
	if (count < 1)
		return (0);
	return (1);
}

static int	ft_take_information(t_stacks *stacks)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return (0);
	while (line)
	{
		line = ft_sup_endl(line);
		if (line)
		{
			if(!(apply_modification(line, stacks)) || ft_strlen(line) < 2)
			{
				free(line);
				return (0);
			}
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

#include <stdio.h>

void	ft_checker(t_stacks *stacks)
{
	int		i;
	long	*sorted_tab;
	int		size;

	size = stacks->size_a;
	sorted_tab = sort_long_tab(stacks->a, stacks->size_a);
	if (!sorted_tab)
		return ;
	// i = 0;
	// while (i < size)
	// {
	// 	printf("%ld | %ld | %ld\n", stacks->a[i], stacks->b[i], sorted_tab[i]);
	// 	i++;
	// }
	// printf("\n");
	if(!(ft_take_information(stacks)))
	{
		free(sorted_tab);
		ft_clean(stacks, 1);
	}
	// i = 0;
	// while (i < size)
	// {
	// 	printf("%ld | %ld | %ld\n", stacks->a[i], stacks->b[i], sorted_tab[i]);
	// 	i++;
	// }
	i = 0;
	while (i < size && stacks->a[i] == sorted_tab[i])
		i++;
	if (i == size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(sorted_tab);
}
