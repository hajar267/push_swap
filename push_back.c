/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:38:16 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/28 12:28:57 by hfiqar           ###   ########.fr       */
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

