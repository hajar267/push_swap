/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:05 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/24 12:10:24 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int find_from_top_bottom(t_list  *a, int i, int j)
{
    t_list  *head;
    t_list  *queue;

    head = a;
    queue = ft_lstlast(a);
    while(head && queue && queue != a)
    {
        if (head ->position >= i && head ->position < j)
        {
           
            return (head->index);
        }
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

    i = 10;
    i = find_from_top_bottom(*a, 0, 1); 
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
    // while(*a)
	// {
	// 	printf("%d\n", (*a) ->index);
	// 	*a = (*a) ->next;
	// }
    ft_get_index(*a);
    // printf("------\n");
    // while(*a)
	// {
	// 	printf("%d\n", (*a) ->index);
	// 	*a = (*a) ->next;
	// }
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
