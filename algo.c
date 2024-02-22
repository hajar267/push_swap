/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:05 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/22 15:42:36 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int find_from_top_bottom(t_list  *a, int i, int j)
{
    t_list  *head;
    t_list  *queue;

    head = a;
    queue = ft_lstlast(a);
    while(head)
    {
        if (head ->position >= i && head ->position < j)
            return (head->index);
        else if (queue -> position >= i && queue ->position < j)
            return (queue->index);
        else
        {
            head = head->next;
            queue = queue->prev;
        }
    }
}

void    check_position_moves(t_list **b, t_list **a, int size, int x, int y)
{
    int i;
    t_list  *head;

    head = *a;
    i = find_from_top_bottom(*a, x, y);
    if (i  >= 0 && i <= size/2)
    {
        while(head -> index != i)
            ft_rotate(a);
        ft_push(a,b);
    }
    else if (i > size/2 && i < size)
    {
        while(head -> index != i)
            ft_re_rotate(a);
        ft_push(a,b);
    }
}
