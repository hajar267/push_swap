/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:40:27 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/13 14:55:20 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	somft(char	*str, int i)
{
	int	som;

	som = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		som = som * 10;
		som = (som + str[i]) - 48;
		i++;
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
	{
		printf("error !int");
		exit(0);
	}
	return (som);
}

int	ft_atoi(char *str)
{
	int	som;
	int	sign;
	int	i ;

	i = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	som = somft(str, i);
	return (som * sign);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(int	content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head -> data = content;
	head -> next = NULL ;
	return (head);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nod;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	nod = ft_lstlast((*lst));
	nod->next = new;
}


t_list    *ft_args(char  **av)
{
    int i;
    char    *str = NULL;
    char    *tmp;
    char    **argv;
    t_list  *a = NULL;

    i = 1;
    while(av[i])
    {
        tmp = ft_strjoin(av[i], " ");
        str = ft_strjoin(str, tmp);
        free (tmp);
        i++;
    }
    argv = ft_split(str, ' ');
    i = 0;
    while(argv[i])
        ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i++])));
    return (a);
}

int	ft_check_dup(char	**argv)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while(argv[i])
	{
		while(argv[j])
		{
			if (argv[i] == argv[j])
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int main(int    ac, char  **av)
{
    t_list  *a;
    if (ac == 1)
        return (0);
    else
        a = ft_args(av);
	while(a)
	{
		printf("%d ", a ->data);
		a = a ->next;
	}
}
