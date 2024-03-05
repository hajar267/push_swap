/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:58:08 by hfiqar            #+#    #+#             */
/*   Updated: 2024/03/05 14:37:54 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_3args(t_list **a)
{
	if ((*a)->data > (*a)->next->data
		&& (*a)->data < (*a)->next->next->data)
		ft_swap(a, 'a');
	else if ((*a)->data > (*a)->next->data
		&& (*a)->next->data > (*a)->next->next->data)
	{
		ft_swap(a, 'a');
		ft_re_rotate(a, 'a');
	}
	else if ((*a)->data > (*a)->next->data
		&& (*a)->next->data < (*a)->next->next->data)
		ft_rotate(a, 'a');
	else if ((*a)->data < (*a)->next->data
		&& (*a)->data < (*a)->next->next->data)
	{
		ft_swap(a, 'a');
		ft_rotate(a, 'a');
	}
	else if ((*a)->data < (*a)->next->data
		&& (*a)->data > (*a)->next->next->data)
		ft_re_rotate(a, 'a');
}

int	ft_get_position_small(t_list *a)
{
	t_list	*second;
	t_list	*head;
	int		j;
	int		i;

	i = 0;
	j = 1;
	head = a;
	second = (head)->next;
	while (second)
	{
		if (head->data < second->data)
		{
			second = second->next;
			j++;
		}
		else
		{
			head = second;
			second = second->next;
			i = j;
			j++;
		}
	}
	return (i);
}

void	ft_5args(t_list **a, t_list **b)
{
	t_list	*head;
	int		i;

	head = *a;
	while (ft_lstsize(*a) > 3)
	{
		ft_get_index(*a);
		i = ft_get_position_small(*a);
		if (head->index != i)
		{
			if (i <= ft_lstsize(*a) / 2)
				ft_rotate(a, 'a');
			else
				ft_re_rotate(a, 'a');
		}
		else
			ft_push(a, b, 'a', 'b');
		head = *a;
	}
	ft_3args(a);
	ft_push(b, a, 'b', 'a');
	ft_push(b, a, 'b', 'a');
}

void	ft_get_index(t_list *a)
{
	t_list	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	ft_get_position(t_list *a)
{
	t_list	*tmp;
	t_list	*head;
	int		j;

	head = a;
	while (head)
	{
		j = 0;
		tmp = a;
		while (tmp)
		{
			if (head->data > tmp->data)
			{
				tmp = tmp->next;
				j++;
			}
			else
				tmp = tmp->next;
		}
		head->position = j;
		head = head->next;
	}
}
