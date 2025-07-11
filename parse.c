/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:40:27 by hfiqar            #+#    #+#             */
/*   Updated: 2024/03/05 20:58:55 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*store(char **argv, int i)
{
	t_list	*a;

	a = NULL;
	while (argv[i])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i++])));
	ft_free_array(argv);
	if (ft_check_sort(a) == 1)
		exit(0);
	if (ft_check_dup(a) == 0)
		exit(write (2, "Error\n", 6));
	ft_get_position(a);
	ft_get_index(a);
	return (a);
}

t_list	*ft_args(char **av)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**argv;
	char	*str_tmp;

	str = NULL;
	if (check_empty(av) == 1)
		exit(write(2, "Error\n", 6));
	i = 1;
	while (av[i])
	{
		tmp = ft_strjoin(av[i++], " ");
		str_tmp = str;
		str = ft_strjoin(str, tmp);
		free(str_tmp);
		free (tmp);
	}
	argv = ft_split(str, ' ');
	free (str);
	return (store(argv, 0));
}

void	ft_free(t_list **b)
{
	t_list	*tmp;

	if (!b || !(*b))
		return ;
	while (*b)
	{
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (ac >= 2)
	{
		a = ft_args(av);
		
		if (ft_lstsize(a) == 2)
		{
			ft_swap(&a, 'a');
			ft_free(&a);
		}
		else if (ft_lstsize(a) <= 5 && ft_lstsize(a) > 2)
		{
			ft_5args(&a, &b);
			ft_free(&b);
			ft_free(&a);
		}
		else if (ft_lstsize(a) > 5)
			if_state(a, b);
	}
}
