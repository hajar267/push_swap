/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:36:11 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/20 21:13:30 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// if args > 5 && args < 500

void    ft_algo_args(t_list *a, t_list  *b)
{
    int i;
    int j;
    int y;
    int x;

    y = 0;
    x = 0;
    j = ft_lstsize(a);
    while(j > y)
    {
        i = j / 4;
        while(i > 0 && j > y)  // check for each int it is in its interval  or no if it is so push it other whise skeep it  ///// function to impl
        {
            while (a)   // a->position include its interval or non
            {
                //function return the index of the first int include interval 
                a = a->next;
            }
            /*
            while(a)
            {
                if (a->position >= y && a->position < i+y)
                    return (a->position)
                else
                    a=a->next;
            }
            head = a;
            head = ft_lstlast(head);
            while(head != a)
            {
                 if (head->position >= y && head->position < i+y)
                    return (head->position)
                else
                    head=head->prev;
            }
            // comparison entre 1ere position and 2ere (la facilite de saute a b)
            check this position if it is in 0 -- size/2 or size/2 --size
            */
            
            i--;
            y++;
        }
        x = ft_lstsize(a) / 4; // not intrss
    }
    
} 
// if(position(i)) include the first ft_lstsize(a) / 2 or the seconde //////// function to impl