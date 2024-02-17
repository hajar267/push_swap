/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:58:08 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/17 20:58:27 by hfiqar           ###   ########.fr       */
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

void    ft_5args(t_list **a, t_list **b)
{
    
}
void    ft_grt5args(t_list  **a, t_list **b)
{
    
}