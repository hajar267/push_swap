/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:42:07 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/12 21:18:24 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int ft_check_dupl(char  **av)
{
    int i = 1;
    int j = 2;
   while(av[j])
   {
    if (av[i] == av[j])
        return(0);
    else
        j++;
        j++;
   }
   return(1);
}

int check_char(char **av)
{
    int i = 1;
    int j = 0;

    while(av[i])
    {
        while(av[i][j])
        {
            if ((av[i][j] < 48 && av[i][j] > 57) && (av[i][j] != '+' && av[i][j] != '-'))
                return (0);
            else
                j++;
        }
        i++;
    }
    return (1);
}

char    **ft_args(char  **av)
{
    int i;
    char    *str;
    char    **argv;

    i = 1;
    while(av[i])
    {
        str = ft_strjoin(av[i], " ");
        i++;
    }
    argv = ft_split(str, ' ');
    return (argv);
}