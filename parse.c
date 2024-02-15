/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:40:27 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/15 21:53:23 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


int	ft_check_sort(t_list	*a)
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
				return(0);
		}
		a = a ->next;
	}
	return(1);
}

int	ft_check_empty(char	**str)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] == ' ' && str[i][j+1] != ' ')
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	somft(char	*str, int i, int signe)
{
	long	som;

	som = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		som = som * 10;
		som = (som + str[i]) - 48;
		i++;
	}
	som = som * signe;
	if (som < INT_MIN || som > INT_MAX)
	{
		printf("%ld", som);
		printf("error max || min int !!!");
		exit(0);
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
	long	som;
	int		signe;
	int		i;

	i = 0;
	signe = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i++] == '-')
		signe = signe * -1;
	else if (str[i] == '+')
		i++;
	som = somft(str, i, signe);
	return (som);
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

int	ft_check_dup(t_list	*a)
{
	t_list	*head;

	head = NULL;
	while(a)
	{
		head = a->next;
		while(head)
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


int	is_empty(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= 9 && str[i] <=13)))
			return (0);
		i++;
	}
	return (1);
}

int	check_empty(char **av)
{
	int i = 0;
	while(av[i])
	{
		int j = 0;
		if (is_empty(av[i]))
			return (1);
		i++;
	}
	return (0);
}


t_list    *ft_args(char  **av)
{
    int		i;
    char    *str = NULL;
    char    *tmp;
    char    **argv;
    t_list  *a;

	a = NULL;
	if (check_empty(av) == 1)
		exit(write(2, "Error!\n", 8));
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
	if(ft_check_dup(a) == 0)
	{
		printf("error duplicated");
		exit(0);
	}
	if (ft_check_sort(a) == 1)
	{
		printf("error sort !!!");
		exit(0);
	}
    return (a);
}
#include <limits.h>

int main(int    ac, char  **av)
{
    t_list  *a;
	t_list	*b;

    if (ac == 1)
        return (0);
    else
        a = ft_args(av);
	// ft_push(&a, &b);
	// ft_swap(&a);
	// ft_rotate(&a);
	// ft_re_rotate(&a);
	while(a)
	{
		printf("%d \n", a ->data);
		a = a ->next;
	}
}
