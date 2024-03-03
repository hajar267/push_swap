/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:05 by hfiqar            #+#    #+#             */
/*   Updated: 2024/03/03 21:24:01 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int find_from_top_bottom(t_list  *a, int y, int chank)
{
    t_list  *head;
    t_list  *queue;

    head = a;
    queue = ft_lstlast(a);
    while(head || queue != a)
    {
        if (head ->position >= y && head ->position < chank)
            return (head->index);
        if (queue -> position >= y && queue ->position < chank)
            return (queue->index);
        head = head->next;
        queue = queue->prev;
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
            ft_rotate(a, 'a');
        else
            ft_re_rotate(a, 'a');
        head = *a;
    }
    ft_push(a, b,'a' ,'b');
    s = y + chank;
    if ((*b)->position < s / 2 && ft_lstsize(*b) > 1)
        ft_rotate(b, 'b'); 
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

int ft_biggest_one(t_list   *b)
{
    t_list  *head;
    t_list  *second;

    head = b;
    second = b->next;
    ft_get_index(b);
    while(second)
    {
        if (head->data < second->data)
            head = second;
        second = second->next;
    }
    return (head->index);
}

void    ft_push_back(t_list **a, t_list **b)
{
    int     i;
    int     size;

    size = ft_lstsize(*b);
    while(size)
    {
        i = ft_biggest_one(*b);
        while ((*b)->index != i)
        {
            if (i < ft_lstsize(*b)/2)
                ft_rotate(b, 'b');
            else
                ft_re_rotate(b, 'b');
        }
        ft_push (b, a, 'b', 'a');
        size--;
    }
}
// prob in push back