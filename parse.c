/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:40:27 by hfiqar            #+#    #+#             */
/*   Updated: 2024/03/01 12:42:54 by hfiqar           ###   ########.fr       */
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

int	somft(char	*str, int i, int sign)
{
	long	som;
	long x;

	som = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9' ))
	{
		som = som * 10;
		som = (som + str[i]) - 48;
		i++;
	}
	if(str[i])
	{
		printf("error !int");
		exit(0);
	}
	x = som * sign;
	if (x > INT_MAX || x < INT_MIN)
	{
		printf("error !!!{int max || int min} ");
		exit(0);
	}
	return (x);
}

int	ft_atoi(char *str)
{
	int	som;
	long	sign;
	int	i ;

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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	node = ft_lstlast((*lst));
	node->next = new;
	new->prev = node;
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
		// printf("adress: %p\n", ft_strjoin(str, tmp));
		// printf("adress: %p\n", str);
		// there is a leaks in str but i don't know how fixed it without segfault
        free (tmp);
        i++;
    }
    argv = ft_split(str, ' ');
	free (str);
	// return(NULL);
    i = 0;
    while(argv[i])
	{
        ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		free(argv[i]);
		i++;
	}
	if (ft_check_sort(a) == 1)
	{
		printf("error sort !!!");
		exit(0);
	}
	if(ft_check_dup(a) == 0)
	{
		printf("error dup");
		exit(0);
	}
	ft_get_position(a);
	ft_get_index(a);    
    return (a);
}

void	printListB(t_list *a)
{
	printf("-----Stack B------\n");
	while (a != NULL)
	{
		printf("data : %d /// index : %d\n", a->data, a->index);
		a = a->next;
	}
}

void	lk()
{
	system("leaks a.out");
}
int main(int    ac, char  **av)
{
	t_list	*a;
	t_list	*b = NULL;
	// int i = 0;

	if ( ac > 2) {
		a = ft_args(av);
		if (ft_lstsize(a) == 2)
			ft_swap(&a, 'a');
		else if (ft_lstsize(a) <= 5 && ft_lstsize(a) > 2)
			ft_5args(&a, &b);
		else
		{
			algo(&a, &b, 5);
			ft_push_back(&a, &b);
		}
		// lk();
		// i = ft_biggest_one(b);
		// printListB(a);
		// printListB(b);
	}
	// else
	// 	printf("Syntax Error");
}
