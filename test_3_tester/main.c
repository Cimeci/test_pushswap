/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:11:39 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/06 16:13:26 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puterror(t_stacks *stacks)
{
	write(2, "Error\n", 6);
	if (stacks->b)
		free(stacks->b);
	if (stacks->a)
		free(stacks->a);
	if (stacks)
		free(stacks);
	exit (0);
}

static long	*ft_tab(char **argv, int count_nb)
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

void	ft_look_error(char **argv, t_stacks *stacks)
{
	if (!ft_check_digit(argv))
		ft_puterror(stacks);
	if (!stacks->a  || !stacks->b || !ft_check_duplicate(stacks->a, stacks->size_a) || !ft_check_int(stacks->a, stacks->size_a))
		ft_puterror(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	
	stacks = malloc(sizeof(t_stacks));
	if (!stacks || argc < 2)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	stacks->size_a = ft_count_nb(argv);
	stacks->a = ft_tab(argv, stacks->size_a);
	if (!stacks->a)
	{
		free(stacks);
		return (0);
	}
	stacks->size_b = 0;
	stacks->b = malloc(sizeof(long) * stacks->size_a);
	if (!stacks->b)
	{
		free(stacks->a);
		free(stacks);
		return (0);
	}
	ft_look_error(argv, stacks);
	ft_algo(stacks);
	free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	free(stacks);
	return (0);
}
