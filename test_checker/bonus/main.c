/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:11:39 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/10 00:01:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	*ft_tab_bonus(char **argv, int count_nb)
{
	long	*tab;
	char	**split;
	int		i;
	int		j;
	int		k;

	tab = malloc(sizeof(long) * count_nb + 8);
	if (!tab)
		return (0);
	i = 0;
	j = 1;
	k = 0;
	while (argv[j])
	{
		split = ft_split(argv[j], ' ');
		i = 0;
		while (split[i])
		{
			tab[k++] = ft_atol(split[i]);
			free(split[i++]);
		}
		free(split);
		j++;
	}
	return (tab);
}

void	ft_init_bonus(t_stacks *stacks, char **argv)
{
	stacks->size_a = ft_count_nb(argv);
	if (stacks->size_a == -1)
		ft_clean(stacks, 1);
	stacks->a = ft_tab_bonus(argv, stacks->size_a);
	if (!stacks->a)
		ft_clean(stacks, 1);
	stacks->size_b = 0;
	stacks->b = malloc(sizeof(long) * stacks->size_a);
	if (!stacks->b)
		ft_clean(stacks, 1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_puterror();
	ft_init_bonus(stacks, argv);
	ft_look_error(argv, stacks);
	ft_checker(stacks);
	free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	free(stacks);
	return (0);
}
