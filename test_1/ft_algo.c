/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:39:30 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 17:39:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Trouver l'index de la plus petite valeur
// static int find_smallest(long *stack, int size)
// {
//     int index = 0;
//     int i = 1;
//     while (i < size)
//     {
//         if (stack[i] < stack[index])
//             index = i;
//         i++;
//     }
//     return (index);
// }

// Trouver l'index de la plus grande valeur
static int find_largest(long *stack, int size)
{
    int index = 0;
    int i = 1;
    while (i < size)
    {
        if (stack[i] > stack[index])
            index = i;
        i++;
    }
    return (index);
}

// Trier les petits ensembles (3 ou 4 éléments)
static void sort_small(long *stack, int size)
{
    if (size == 2 && stack[0] > stack[1])
        sa(stack);
    else if (size == 3)
    {
        if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2])
            sa(stack);
        else if (stack[0] > stack[1] && stack[1] > stack[2])
        {
            sa(stack);
            rra(stack, 3);
        }
        else if (stack[0] > stack[1] && stack[1] < stack[2])
            ra(stack, 3);
        else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] < stack[2])
        {
            sa(stack);
            ra(stack, 3);
        }
        else if (stack[0] < stack[1] && stack[1] > stack[2])
            rra(stack, 3);
    }
}

// Créer les chunks basés sur les valeurs triées
static int *create_chunks(long *stack, int size, int chunk_count)
{
    int *chunks;
    long *sorted_stack;
    int i, step;

    chunks = malloc(sizeof(int) * chunk_count);
    sorted_stack = malloc(sizeof(long) * size);
    if (!chunks || !sorted_stack)
        return (NULL);

    // Copier et trier la pile
    i = 0;
    while (i < size)
    {
        sorted_stack[i] = stack[i];
        i++;
    }
    // Tri basique (remplace qsort pour respecter la norme)
    i = 0;
    while (i < size - 1)
    {
        int j = i + 1;
        while (j < size)
        {
            if (sorted_stack[i] > sorted_stack[j])
            {
                long temp = sorted_stack[i];
                sorted_stack[i] = sorted_stack[j];
                sorted_stack[j] = temp;
            }
            j++;
        }
        i++;
    }

    // Définir les chunks
    step = size / chunk_count;
    i = 0;
    while (i < chunk_count)
    {
        chunks[i] = sorted_stack[(i + 1) * step - 1];
        i++;
    }
    free(sorted_stack);
    return (chunks);
}

// Trier la pile principale
static void ft_sort(long *stack_a, long *stack_b, int *size_a, int *size_b, int chunk_count)
{
    int *chunks;
    int current_chunk;
    int i;

    // Créer les chunks
    chunks = create_chunks(stack_a, *size_a, chunk_count);
    if (!chunks)
        return;

    // Pousser les éléments dans B en fonction des chunks
    current_chunk = 0;
    while (current_chunk < chunk_count)
    {
        i = 0;
        while (i < *size_a)
        {
            if (stack_a[0] <= chunks[current_chunk])
            {
                pb(stack_a, stack_b, size_a, size_b);
                if (stack_b[0] > chunks[current_chunk] / 2)
                    rb(stack_b, *size_b); // Améliorer la répartition
            }
            else
                ra(stack_a, *size_a);
            i++;
        }
        current_chunk++;
    }

    // Réintégrer les éléments de B dans A
    while (*size_b > 0)
    {
        int largest = find_largest(stack_b, *size_b);
        push_to_top(stack_b, largest, *size_b);
        pa(stack_a, stack_b, size_a, size_b);
    }
    free(chunks);
}

// Fonction principale
void ft_algo(long *stack_a, int count_nb)
{
    long stack_b[1000];
    int size_a = count_nb;
    int size_b = 0;
    int chunk_count;

    if (count_nb <= 5)
        sort_small(stack_a, count_nb);
    else
    {
        // Définir le nombre de chunks dynamiquement
        if (count_nb <= 100)
            chunk_count = 5; // Diviser en 5 chunks pour 100 éléments
        else
            chunk_count = 11; // Diviser en 11 chunks pour 500 éléments
        ft_sort(stack_a, stack_b, &size_a, &size_b, chunk_count);
    }
}
