/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:41:50 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/07 17:26:45 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}

int	ft_count_nb(char **str)
{
	int	count;
	int	j;
	int	i;

	count = 0;
	j = 0;
	i = 0;
	while (str[j])
	{
		if (str[j][0] == '\0')
			return (-1);
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] != ' ')
				break ;
			if (str[j][i + 1] == '\0')
				return (-1);
			i++;
		}
		count += ft_count_word(str[j], ' ');
		j++;
	}
	return (count - 1);
}
