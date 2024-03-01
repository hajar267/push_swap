/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:40:27 by hfiqar            #+#    #+#             */
/*   Updated: 2024/03/01 21:56:16 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
t_list  *norm(char   **argv, int i)
{
    t_list  *a;

    while (argv[i])
    {
        ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
        free(argv[i]);
        i++;
    }
    if (ft_check_sort(a) == 1)
        exit(write (2, "error\n", 6));
    if (ft_check_dup(a) == 0)
        exit(write (2, "error\n", 6));
    ft_get_position(a);
	ft_get_index(a);
    return (a);
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
		exit(write(2, "Error\n", 6));
    i = 1;
    while(av[i])
    {
        tmp = ft_strjoin(av[i], " ");
        str = ft_strjoin(str, tmp);
        free (tmp);
        i++;
    }
    argv = ft_split(str, ' ');
	free (str);
    return (norm(argv, 0));
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

	if ( ac > 2) 
	{
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
	}
}
