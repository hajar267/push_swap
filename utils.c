/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:42:07 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/11 17:39:13 by hfiqar           ###   ########.fr       */
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

char    **ft_arg(char   **av)
{
    int i = 1;
    int j = 0;
    int x;
    int y;
    char    **str;
    char    **store;
    while (av[i])
    {
        if(strlen(av[i]) > 1) 
        {
            x = 0;
            str = ft_split(av[i], ' ');
            while(str[x] || y < ft_strlen(str[x]))
                store[j] = str[x][y];
            i++;
        }
        else if(strlen(av[i] == 1))
            store[j++] = av[i++];
        else
        {
                // mssj d'err <veuillez entrer les args>
        }
    }
    return (store);
}

#include<stdio.h>
char    **ft_make_esp(char   **str)
{
    char    **sts;
    int i=0;
    int j=0;
    sts = malloc(100);
    while(str[i])
    {
        sts[j] = str[i];
        j++;
        sts[j] = " ";
        j++;
        i++;
    }
        printf("%s", sts[2]);
    return (sts);
}
int main()
{
    char *s[] = {"5","7","9","2","4","202"};
    int i =0;
    char    **str = ft_make_esp(s);
    while(i < 12)
    {
        i++;
    }
}
