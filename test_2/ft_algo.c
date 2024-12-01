/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:44:15 by marvin            #+#    #+#             */
/*   Updated: 2024/12/01 17:44:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Trouver l'index de la plus petite valeur
int find_smallest(long *stack, int size)
{
    int index = 0;
    int i = 1;
    while (i < size)
    {
        if (stack[i] < stack[index])
            index = i;
        i++;
    }
    return (index);
}

// Trier les petits ensembles (3 à 5 éléments)
void sort_small(long *stack, int size)
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
    else if (size == 4 || size == 5)
    {
        // Pour les tailles de 4 ou 5, gérer les éléments avec pb et pa
        int size_b = 0;
        while (size > 3)
        {
            int smallest = find_smallest(stack, size);
            push_to_top(stack, smallest, size);
            pb(stack, stack + size, &size, &size_b);
            size--;
            size_b++;
        }
        sort_small(stack, 3); // Trier les 3 derniers éléments
        while (size_b > 0)
        {
            pa(stack, stack + size, &size, &size_b);
            size++;
            size_b--;
        }
    }
}

// Trouver l'index où insérer un élément dans A
int find_insert_position(long *stack_a, int size_a, long value)
{
    int i = 0;
    while (i < size_a - 1)
    {
        if (stack_a[i] < value && stack_a[i + 1] > value)
            return (i + 1); 
        i++;
    }
    return (stack_a[0] > value ? 0 : size_a);
}

// Réintégrer les éléments de B dans A en ordre croissant
void reintegrate_sorted_to_a(long *stack_a, long *stack_b, int *size_a, int *size_b)
{
    while (*size_b > 0)
    {
        int smallest = find_smallest(stack_b, *size_b);
        int insert_position;

        push_to_top(stack_b, smallest, *size_b);
        insert_position = find_insert_position(stack_a, *size_a, stack_b[0]);

        if (insert_position <= *size_a / 2)
        {
            while (insert_position-- > 0)
                ra(stack_a, *size_a);
        }
        else
        {
            insert_position = *size_a - insert_position;
            while (insert_position-- > 0)
                rra(stack_a, *size_a);
        }

        pa(stack_a, stack_b, size_a, size_b);
    }
}

// Trier chaque chunk avant de les envoyer dans B
void push_chunk_to_b_sorted(long *stack_a, long *stack_b, int *size_a, int *size_b, int chunk_min, int chunk_max)
{
    int i = 0;

    while (i < *size_a)
    {
        if (stack_a[0] >= chunk_min && stack_a[0] <= chunk_max)
        {
            pb(stack_a, stack_b, size_a, size_b);

            // Si \( B \) contient au moins deux éléments, positionner correctement
            if (*size_b > 1 && stack_b[0] < stack_b[1])
                sb(stack_b); // Trier \( B \) pour garantir l'ordre croissant
        }
        else
        {
            ra(stack_a, *size_a);
        }
        i++;
    }
}

// Créer les chunks basés sur les valeurs triées
int *create_chunks(long *stack, int size, int chunk_count)
{
    int *chunks;
    long *sorted_stack;
    int i, step;

    chunks = malloc(sizeof(int) * chunk_count);
    sorted_stack = malloc(sizeof(long) * size);
    if (!chunks || !sorted_stack)
        return (NULL);

    i = 0;
    while (i < size)
    {
        sorted_stack[i] = stack[i];
        i++;
    }
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

// Trier la pile principale avec des chunks triés
void ft_sort_v2(long *stack_a, long *stack_b, int *size_a, int *size_b, int chunk_count)
{
    int *chunks;
    int current_chunk;

    chunks = create_chunks(stack_a, *size_a, chunk_count);
    if (!chunks)
        return;

    current_chunk = 0;
    while (current_chunk < chunk_count)
    {
        push_chunk_to_b_sorted(stack_a, stack_b, size_a, size_b, (current_chunk == 0 ? INT_MIN : chunks[current_chunk - 1]), chunks[current_chunk]);
        current_chunk++;
    }

    reintegrate_sorted_to_a(stack_a, stack_b, size_a, size_b);
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
        if (count_nb <= 100)
            chunk_count = 5;
        else
            chunk_count = 11;
        ft_sort_v2(stack_a, stack_b, &size_a, &size_b, chunk_count);
    }
}
