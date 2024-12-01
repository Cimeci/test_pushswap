/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:11:39 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/26 10:30:22 by inowak--         ###   ########.fr       */
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
	int		count_nb;
	long	*tab;

	if (argc < 2)
		return (0);
	if (!(ft_check_digit(argv)))
		return (0);
	count_nb = ft_count_nb(argv);
	if (!count_nb)
	{
		ft_puterror("Error\nparams false\n");
		return (0);
	}
	tab = ft_tab(argv, count_nb);
	if (!(ft_check_duplicate(tab, count_nb)))
		return (0);
	if (!(ft_check_int(tab, count_nb)))
		return (0);
	else
		ft_algo(tab, count_nb);
	free(tab);
	return (0);
}
