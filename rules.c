/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:24:18 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/15 12:49:48 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_swap(t_list **a)
{
    t_list *head;
    t_list *root;

    head = *a;
    root = head->next;
    head->next = root->next;
    root->next = head;
    *a = root;
}


void    ft_push(t_list  **a, t_list  **b)
{
    t_list  *head;
    t_list  *root;
    
    root = *b;
    head = *a;
    *a = head ->next;
    head ->next = root;
    *b = head;
}

void    ft_rotate(t_list    **a)
{
    t_list  *head;
    t_list  *root;

    head = *a;
    root = ft_lstlast(&a);
}

void    ft_re_rotate(t_list *a)
{

}
