/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:05 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/27 17:37:53 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int find_from_top_bottom(t_list  *a, int y, int chank)
{
    t_list  *head;
    t_list  *queue;

    head = a;
    queue = ft_lstlast(a);
    while(head && queue && queue != a)
    {
        if (head ->position >= y && head ->position < chank)
            return (head->index);
        else if (queue -> position >= y && queue ->position < chank)
            return (queue->index);
        else
        {
            head = head->next;
            queue = queue->prev;
        }
    }
    return (0);
}

void    check_position_moves(t_list **b, t_list **a, int size, int y, int chank)
{
    int i;
    int s;
    t_list  *head;

    head = *a;

    i = find_from_top_bottom(*a, y, chank);
    while(head ->index != i)
    {
        if (i <= size / 2)
            ft_rotate(a);
        else
            ft_re_rotate(a);
        head = *a;
    }
    ft_push(a, b);
    s = y + chank;
    if ((*b)->position < s / 2 && ft_lstsize(*b) > 1)
        ft_rotate(b); 
}

void   algo(t_list **a, t_list  **b, int dev)
{
    int size;
    int chank;
    int y;
    int tmp1;
    int x;
    int tmp;

    tmp = ft_lstsize(*a);
    chank = tmp / dev;
    y = 0;
    while(y < tmp)
    {
        x = y;
        tmp1 = chank;
        while(tmp1 > 0 && ft_lstsize(*a) > 0)
        {
            size = ft_lstsize(*a);
            check_position_moves(b, a, size, x, chank + x);
            ft_get_index(*a);
            y++;
            tmp1--;
        }
    }
}
