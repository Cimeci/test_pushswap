/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:58:15 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/05 17:46:26 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_start_b(t_stacks *stacks)
{
	if (stacks->size_a > 4)
		pb(stacks);
	pb(stacks);

	// if (stacks->b[0] > stacks->b[1])
	// 	sb(stacks);
}

static int ft_search_target(t_stacks *stacks, int index_a)
{
    int i;
    int max = ft_search_max_for_b(stacks);
    int min = ft_search_min_for_b(stacks);

    // Si l'élément dans A est plus grand que le max de B ou plus petit que le min de B
    if (stacks->a[index_a] > stacks->b[max] || stacks->a[index_a] < stacks->b[min])
        return (max);

    // Rechercher la position correcte dans la pile B
    i = 0;
    while (i < stacks->size_b - 1)
    {
        if (stacks->a[index_a] < stacks->b[i] && stacks->a[index_a] > stacks->b[i + 1])
            return (i + 1);
        i++;
    }
    return (0);
}

static int count_operation(t_stacks *stacks, int index)
{
    int count_a;
    int count_b;
    int target;

    // Compter les mouvements nécessaires pour amener l'élément d'A au sommet
    if (index <= stacks->size_a / 2)
        count_a = index;
    else
        count_a = stacks->size_a - index;

    // Trouver la cible dans B
    target = ft_search_target(stacks, index);

    // Compter les mouvements nécessaires pour aligner la cible dans B
    if (target <= stacks->size_b / 2)
        count_b = target;
    else
        count_b = stacks->size_b - target;

    return (count_a + count_b);
}

static int index_to_change(t_stacks *stacks)
{
    int i;
    int best_index;
    int min_operations;
    int current_operations;

    i = 0;
    best_index = 0;
    min_operations = count_operation(stacks, 0);

    while (i < stacks->size_a)
    {
        current_operations = count_operation(stacks, i);
        if (current_operations < min_operations)
        {
            best_index = i;
            min_operations = current_operations;
        }
        i++;
    }
    return (best_index);
}


void	ft_sort_a_to_b(t_stacks *stacks)
{
    int index;
    int target;

    while (stacks->size_a > 3)
    {
        index = index_to_change(stacks);
        target = ft_search_target(stacks, index);

        // Aligner A et B pour le mouvement
        push_to_top_stack_a(stacks, index);
        push_to_top_stack_b(stacks, target);

        // Pousser l'élément de A vers B
        pb(stacks);
    }

    // Trier les 3 éléments restants dans A
    sort_three(stacks);
}
