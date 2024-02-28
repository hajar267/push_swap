/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:38:16 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/28 20:31:50 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int ft_biggest_one(t_list   *b)
{
    t_list  *head;
    t_list  *second;

    head = b;
    second = b->next;
    ft_get_index(b);
    while(second)
    {
        if (head->data > second->data)
            second = second->next;
        else
        {
            head = second;
            second = second->next;
        }
    }
    return (head->index);
}

void    ft_push_back(t_list **a, t_list **b)
{
    t_list  *head;
    int     i;
    int     y;
    int     size;

    head = *b;
    y = 0;
    size = ft_lstsize(*b);
    while(size > y)
    {
        i = ft_biggest_one(*b);
        while ((*b)->position != i)
        {
            if (i <= ft_lstsize(*b)/2)
                ft_rotate(b);
            else
                ft_re_rotate(b);
        }
        ft_push (b, a);
        y++;
    }
}
