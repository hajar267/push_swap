/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:36:49 by hfiqar            #+#    #+#             */
/*   Updated: 2024/03/04 22:22:47 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_list *a)
{
	t_list	*head;

	head = NULL;
	while (a)
	{
		head = a ->next;
		while (head)
		{
			if (a ->data < head ->data)
				head = head ->next;
			else
				return (0);
		}
		a = a ->next;
	}
	return (1);
}

int	ft_check_dup(t_list *a)
{
	t_list	*head;

	head = NULL;
	while (a)
	{
		head = a->next;
		while (head)
		{
			if (a->data == head->data)
				return (0);
			else
				head = head->next;
		}
		a = a ->next;
	}
	return (1);
}

int	check_empty(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ' || (av[i][j] >= 9 && av[i][j] <= 13))
				j++;
			else
				break ;
		}
		if (!av[i][j])
			return (1);
		i++;
	}
	return (0);
}

int	somft(char *str, int i, int sign)
{
	long	som;
	long	x;

	som = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9' ))
	{
		som = som * 10;
		som = (som + str[i]) - 48;
		i++;
	}
	if (str[i])
		exit(write(2, "error\n", 6));
	x = som * sign;
	if (x > INT_MAX || x < INT_MIN)
		exit(write(2, "error\n", 6));
	return (x);
}

int	ft_atoi(char *str)
{
	int		som;
	long	sign;
	int		i ;

	i = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] != '\0' && str[i] == '+')
		i++;
	som = somft(str, i, sign);
	return (som);
}
