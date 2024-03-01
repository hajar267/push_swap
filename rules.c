/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:24:18 by hfiqar            #+#    #+#             */
/*   Updated: 2024/03/01 12:32:52 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_swap(t_list **a, char c)
{
    t_list *first_node;
    t_list *second_node;

    first_node = *a;
    second_node = (*a)->next;
    first_node->next = second_node->next;
    second_node->next = first_node;
    second_node ->prev = NULL;
    first_node ->prev = second_node;
    *a = second_node;
    if (c == 'a')
        write (1, "sa\n", 3);
    else
        write(1, "sb\n", 3);
}

void    ft_push(t_list  **a, t_list  **b, char c, char z)
{
    t_list  *head_a;
    t_list  *head_b;
    
    if (!ft_lstsize(*a))
        return ;
    head_b = *b;
    head_a = *a;
    *a = head_a->next;
    if (*a)
        (*a)->prev = NULL;
    head_a->next = head_b;
    head_a->prev= NULL;
    if(head_b)
        head_b->prev = head_a;
    *b = head_a;
    if (c == 'a' && z == 'b')
        write (1, "pb\n", 3);
    else
        write (1, "pa\n", 3);
}

void    ft_rotate(t_list    **a, char c)
{
    t_list  *first;
    t_list  *last;

    first = *a;
    last = ft_lstlast(*a);
    last ->next = first;
    first->prev = last;
    *a = (*a) ->next;
    (*a)->prev = NULL;
    first ->next = NULL;
    if (c == 'a')
        write (1, "ra\n", 3);
    else
        write (1, "rb\n", 3);
}

void    ft_re_rotate(t_list **a, char c)
{
    t_list  *first;
    t_list  *last;

    first = *a;
    last = ft_lstlast(*a);
    last ->next = first;
    first ->prev = last;
    last->prev->next = NULL;
    last->prev = NULL;
    *a = last;
    if (c == 'a')
        write (1, "rra\n", 4);
    else
        write (1, "rrb\n", 4);
}
