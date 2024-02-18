/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:58:08 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/18 21:45:44 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    ft_3args(t_list **a)
{
    t_list  *head;
        head = (*a)->next;
        if ((*a)->data > head ->data)
        {
            if ((*a)->next->data < head ->next->data && (*a) ->data < head->next->data)
                ft_swap(a);
            else if((*a)->next->data < head ->next->data && (*a) ->data > head->next->data)
                ft_rotate(a);
            else if((*a)->next->data > head ->next->data && (*a) ->data > head->next->data)
                {
                    ft_rotate(a);
                    ft_swap(a);
                }
        }
        else
        {
            if ((*a)->data < head ->next->data)
            {
                ft_re_rotate(a);
                ft_swap(a);
            }
            else if ((*a)->data > head ->next->data)
                ft_re_rotate(a);
        }
    }

int ft_get_position_small(t_list    *a)
{
    t_list  *head;
    t_list  *tmp;
    int i = 0;
    int j = 1;
    tmp = a;
    head = (tmp)->next;
        while (head)
        {
            if (tmp->data < head ->data)
            {
                head = head ->next;
                j++;
            }
            else
            {
                tmp = head;
                head = head ->next;
                i = j;
                j++;
            }
        }
        return (i);
}

void    ft_5args(t_list **a, t_list **b)
{
    t_list  *head;
    t_list  *tmp;
    tmp = *a;
    static  int i =0;
    if (ft_lstsize(*a) == 5)
    {
        if (ft_get_position_small(*a) == 0)
            ft_push(a, b);
        else if (ft_get_position_small(*a) == 1)
        {
            ft_rotate(a);
            ft_push(a, b);
        }
        else if (ft_get_position_small(*a) == 2)
        {
            ft_rotate(a);
            ft_rotate(a);
            ft_push(a, b);
        }
        else if (ft_get_position_small(*a) == 3)
        {
            ft_re_rotate(a);
            ft_re_rotate(a);
            ft_push(a, b);
        }
        else
        {
            ft_re_rotate(a);
            ft_push(a, b);
        }

        ft_5args(a, b);
    }
    else if (ft_lstsize(*a) == 4)
    {
        if (ft_get_position_small(*a) == 0)
            ft_push(a, b);
        else if (ft_get_position_small(*a) == 1)
        {
            ft_rotate(a);
            ft_push(a, b);
        }
        else if (ft_get_position_small(*a) == 2)
        {
            ft_rotate(a);
            ft_rotate(a);
            ft_push(a, b);
        }
        else
        {
            ft_re_rotate(a);
            ft_push(a, b);
        }
        ft_5args(a, b);
    }
    else
        ft_3args(a);
    ft_push(b, a);
    ft_push(b, a);
}
