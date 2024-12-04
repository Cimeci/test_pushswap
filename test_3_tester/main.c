/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:11:39 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/04 13:38:44 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
}

static long	*ft_tab(char **argv, int count_nb)
{
	long	*tab;
	char	**split;
	int		i;
	int		j;
	int		k;

	tab = malloc(sizeof(long) * count_nb);
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

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (argc < 2 || !stacks)
		return (0);
	if (!ft_check_digit(argv))
	{
		ft_puterror("Error\nInvalid digits\n");
		free(stacks);
		return (0);
	}
	stacks->size_a = ft_count_nb(argv);
	if (stacks->size_a <= 0)
	{
		ft_puterror("Error\nInvalid number count\n");
		free(stacks);
		return (0);
	}
	stacks->a = ft_tab(argv, stacks->size_a);
	stacks->b = malloc(sizeof(long) * stacks->size_a);
	if (!stacks->a || !stacks->b || !ft_check_duplicate(stacks->a, stacks->size_a) || !ft_check_int(stacks->a, stacks->size_a))
	{
		ft_puterror("Error\nInvalid stack initialization\n");
		free(stacks->a);
		free(stacks);
		return (0);
	}
	ft_algo(stacks);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}
