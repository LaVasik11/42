/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2021/07/09 18:33:23 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int get_position(t_list *stack, int index)
{
    int pos;

    pos = 0;
    while (stack)
    {
        if (stack->index == index)
            return (pos);
        pos++;
        stack = stack->next;
    }
    return (-1);
}

int find_max_index(t_list *stack)
{
    int max;

    if (!stack)
        return (-1);
    max = stack->index;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return (max);
}

void push_chunks(t_list **a, t_list **b, int chunk)
{
    int count;

    count = 0;
    while (*a)
    {
        if ((*a)->index <= count)
        {
            pb(a, b);
            rb(b);
            count++;
        }
        else if ((*a)->index <= count + chunk)
        {
            pb(a, b);
            count++;
        }
        else
            ra(a);
    }
}

void push_back_to_a(t_list **a, t_list **b)
{
    int max;
    int pos;
    int b_size;

    while (*b)
    {
        max = find_max_index(*b);
        b_size = ft_lstsize(*b);
        pos = get_position(*b, max);
        if (pos <= b_size / 2)
        {
            while ((*b)->index != max)
                rb(b);
        }
        else
        {
            while ((*b)->index != max)
                rrb(b);
        }
        pa(a, b);
    }
}

void butterfly_sort(t_list **a, t_list **b, int size)
{
    int chunk;

    if (size <= 100)
        chunk = 20;
    else
        chunk = 45;
    push_chunks(a, b, chunk);
    push_back_to_a(a, b);
}
