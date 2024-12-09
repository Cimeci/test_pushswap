/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:11:37 by marvin            #+#    #+#             */
/*   Updated: 2024/12/07 23:11:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

static long	*sort_long_tab_extension(long *sorted_tab, int size)
{
	long	tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted_tab[i] > sorted_tab[j])
			{
				tmp = sorted_tab[i];
				sorted_tab[i] = sorted_tab[j];
				sorted_tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sorted_tab);
}

long	*sort_long_tab(long *tab, int size)
{
	long	*sorted_tab;
	int		i;

	sorted_tab = malloc(sizeof(long) * size);
	if (!sorted_tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted_tab[i] = tab[i];
		i++;
	}
	sorted_tab = sort_long_tab_extension(sorted_tab, size);
	return (sorted_tab);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
