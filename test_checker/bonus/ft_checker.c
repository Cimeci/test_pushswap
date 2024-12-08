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

	if (!line || ft_strlen(line) == 0)
		return (NULL);
	tab = malloc(sizeof(char) * ft_strlen(line));
	if (!tab)
		return (NULL);
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

static void	ft_take_information(t_stacks *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		line = ft_sup_endl(line);
		if (line)
		{
			apply_modification(line, stacks);
			free(line);
		}
		line = get_next_line(0);
	}
}

void	ft_checker(t_stacks *stacks)
{
	int		i;
	long	*sorted_tab;

	sorted_tab = sort_long_tab(stacks->a, stacks->size_a);
	if (!sorted_tab)
		return ;
	ft_take_information(stacks);
	i = 0;
	while (i < stacks->size_a && stacks->a[i] == sorted_tab[i])
		i++;
	if (i == stacks->size_a)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(sorted_tab);
}
