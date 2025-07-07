/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:51 by hfiqar            #+#    #+#             */
/*   Updated: 2024/03/05 15:33:08 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_state(t_list *a, t_list *b)
{
	if (ft_lstsize(a) <= 100)
	{
		algo(&a, &b, 5);
		ft_push_back(&a, &b);
		ft_free(&b);
		ft_free(&a);
	}
	else if (ft_lstsize(a) > 100)
	{
		algo(&a, &b, 9);
		ft_push_back(&a, &b);
		ft_free(&b);
		ft_free(&a);
	}
}
