/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:40:27 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/12 21:23:35 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static	int	somft(char	*str, int i)
{
	int	som;

	som = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9' ))
	{
		som = som * 10;
		som = (som + str[i]) - 48;
		i++;
	}
	return (som);
}

int	ft_atoi(char *str)
{
	int	som;
	int	sign;
	int	cnt;
	int	i ;

	i = 0;
	cnt = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-' ||  str[i] == '+')
		{
			sign = sign * -1;
		}
		cnt++;
		i++;
	}
	if (cnt > 1) //modifie cnt printf("error") si le cnt est plus que 1 pour le (+) et le (-)
		return (0);
	som = somft(str, i);
	return (som * sign);
}

int count_arg(char  **av)   //i is a lenght of arguments --> if the arguments is like that <1 0 5 8 5> it's normale but if it's like <1 2 8 9 "2 6 7" 4> it must to split it to a normal arg
{
    int i = 1;
    while (av[i])
        i++;
    return (i);
}

t_list  *place(char  **av)
{
    t_list  *head = NULL;
    int i = count_arg(av);
    t_list  *a[i];
    int j = 1;
    head = a;
    while(j <= i)
    {
        head = malloc(sizeof(t_list));
        head -> data = ft_atoi(av[j]);
        head = head ->next;
        j++;
        i--;
    }
    head ->next = NULL;
    a[i] = head;
    return (a);
}

int main(int    ac, char  **av)
{
    t_list  *a;
    if (ac < 2)
        return (0);
    else
        a = place(av);
}
