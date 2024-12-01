/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:27:59 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/26 10:46:40 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_error_check_digit(char c)
{
	if ((c < '0' || c > '9') && c != '\0')
	{
		ft_puterror("Error\ncharacter fasle\n");
		return (0);
	}
	return (1);
}

int	ft_check_digit(char **argv)
{
	int	j;
	int	i;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == ' ')
				i++;
			else
			{
				if (argv[j][i] == '-' || argv[j][i] == '+')
					i++;
				if (!ft_error_check_digit(argv[j][i]))
					return (0);
				i++;
			}
		}
		j++;
	}
	return (1);
}

int	ft_check_int(long *tab, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (tab[j] > 2147483647 || tab[j] < -2147483648)
		{
			ft_puterror("Error\nnot a int\n");
			free(tab);
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_check_duplicate(long *tab, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size && tab[j])
	{
		i = 1;
		while (j + i < size)
		{
			if (tab[j] == tab[j + i])
			{
				ft_puterror("Error\nduplicate\n");
				free(tab);
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}
