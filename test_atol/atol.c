/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:52:01 by marvin            #+#    #+#             */
/*   Updated: 2024/12/06 23:52:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *nptr)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;

	// Ignorer les espaces initiaux si besoin (optionnel selon le contexte)
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;

	// Gérer les signes
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}

	// Ignorer les zéros initiaux
	while (nptr[i] == '0')
		i++;

	// Construire le nombre
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}

	return (sign * nb);
}

#include <stdio.h>

int main()
{
    printf("%ld\n", ft_atol("0"));           // 0
    printf("%ld\n", ft_atol("-0"));          // 0
    printf("%ld\n", ft_atol("00"));          // 0
    printf("%ld\n", ft_atol("-00"));         // 0
    printf("%ld\n", ft_atol("123"));         // 123
    printf("%ld\n", ft_atol("-123"));        // -123
    printf("%ld\n", ft_atol("   -0042"));    // -42
    return 0;
}
