/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:05 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/24 11:15:10 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int find_from_top_bottom(t_list  *a, int i, int j)
{
    t_list  *head;
    t_list  *queue;

    head = a;
    while(head && queue && queue != a)
    {
        queue = ft_lstlast(a);
        if (head ->position >= i && head ->position < j)
            return (head->index);
        else if (queue -> position >= i && queue ->position < j)
        {
            return (queue->index);
        }
        else
        {
            head = head->next;
            queue = ft_lstlast(head);
        }
    }
    return (0);
}

void    check_position_moves(t_list **b, t_list **a, int size, int x, int y)
{
    int i;
    t_list  *head;

    head = *a;

    i = find_from_top_bottom(*a, x, y); 
        printf("---%d---\n", i);  // it return 0 instead 3
        //printf("---%d---\n", x);
        (void)x;  // it return 0 instead 3
        // printf("---%d---\n", y);  // it return 0 instead 3
    // // //      while(*a)
	// {
	// 	printf("%d\n", (*a) ->data);
	// 	*a = (*a) ->next;
	// }
    while(head ->index != i)
    {
        // printf("---%d---\n", head->index);
        if (i <= size /2)
            ft_rotate(a);
        else
            ft_re_rotate(a);
        head = *a;
    }
    ft_push(a, b);
    if ((*b)->position < x + y / 2 && ft_lstsize(*b) > 1)
        ft_rotate(b);
    ft_get_index(*a);
}

void    algo(t_list *a, t_list  *b, int dev)
{
    int size;
    int chank;
    int y;

    size = ft_lstsize(a);
    chank = size / dev;
    y = 0;
    while(y < size)
    {
        check_position_moves(&b, &a, size, y, chank + y);
        y++;
    }
}
