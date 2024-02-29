/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:58:08 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/29 10:49:09 by hfiqar           ###   ########.fr       */
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
                ft_swap(a, 'a');
            else if((*a)->next->data < head ->next->data && (*a) ->data > head->next->data)
                ft_rotate(a, 'a');
            else if((*a)->next->data > head ->next->data && (*a) ->data > head->next->data)
                {
                    ft_rotate(a, 'a');
                    ft_swap(a, 'a');
                }
        }
        else
        {
            if ((*a)->data < head ->next->data)
            {
                ft_re_rotate(a, 'a');
                ft_swap(a, 'a');
            }
            else if ((*a)->data > head ->next->data)
                ft_re_rotate(a, 'a');
        }
    }

int ft_get_position_small(t_list    *a)
{
    t_list  *second;
    t_list  *head;
    int i = 0;
    int j = 1;
    head = a;
    second = (head)->next;
        while (second)
        {
            if (head->data < second ->data)
            {
                second = second ->next;
                j++;
            }
            else
            {
                head = second;
                second = second ->next;
                i = j;
                j++;
            }
        }
        return (i);
}

void    if_5(t_list **a, t_list **b)
{
    if (ft_get_position_small(*a) == 0)
        ft_push(a, b, 'a', 'b');
    else if (ft_get_position_small(*a) == 1)
    {
        ft_rotate(a, 'a');
        ft_push(a, b, 'a', 'b');
    }
    else if (ft_get_position_small(*a) == 2)
    {
        ft_rotate(a, 'a');
        ft_rotate(a, 'a');
        ft_push(a, b, 'a', 'b');
    }
    else if (ft_get_position_small(*a) == 3)
    {
        ft_re_rotate(a, 'a');
        ft_re_rotate(a, 'a');
        ft_push(a, b, 'a', 'b');
    }
    else
    {
        ft_re_rotate(a, 'a');
        ft_push(a, b, 'a', 'b');
    }
}

void    if_4(t_list **a, t_list **b)
{
    if (ft_get_position_small(*a) == 0)
        ft_push(a, b, 'a', 'b');
    else if (ft_get_position_small(*a) == 1)
    {
        ft_rotate(a, 'a');
        ft_push(a, b, 'a', 'b');
    }
    else if (ft_get_position_small(*a) == 2)
    {
        ft_rotate(a, 'a');
        ft_rotate(a, 'a');
        ft_push(a, b, 'a', 'b');
    }
    else
    {
        ft_re_rotate(a, 'a');
        ft_push(a, b, 'a', 'b');
    }
}

void    ft_5args(t_list **a, t_list **b)
{
    // t_list  *head;
    t_list  *tmp;

    tmp = *a;
    if (ft_lstsize(*a) == 5)
    {
        if_5(a , b);
        ft_5args(a, b);
    }
    else if (ft_lstsize(*a) == 4)
    {
        if_4(a, b);
        ft_5args(a, b);
    }
    else
        ft_3args(a);
    ft_push(b, a, 'b', 'a');
    ft_push(b, a, 'b','a');
}


void ft_get_index(t_list    *a)
{
    t_list  *tmp;
    int i;

    tmp = a;
    i = 0;
        while (tmp)
        {
            tmp->index = i;
            tmp = tmp->next;
            i++;
        }    
}

void    ft_get_position(t_list  *a)
{
  t_list    *tmp;
  t_list    *head;
  int j;
  
  head = a;
  while(head)
  {
    j = 0;
    tmp = a;
    while(tmp)
    {
        if (head->data > tmp->data)
        {
            tmp = tmp->next;
            j++;
        }
        else
            tmp=tmp->next;
    }
    head->position = j;
    head = head->next;
  }
}



