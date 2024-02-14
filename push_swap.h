/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:29:34 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/14 12:40:41 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#ifndef NULL
#include <sys/_types.h>
#define NULL   __DARWIN_NULL
#endif

typedef struct s_list
{
    struct s_list   *next;
    int             data;
}t_list;

int	ft_compt_word(char const *st, char t);
int	ft_compt_chr(char const *str, char r);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
t_list    *ft_args(char  **av);
int	somft(char	*str, int i);
int	ft_atoi(char *str);
t_list  **place(char  **av);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_check_dup(t_list *a);
int	ft_check_empty(char	**str);

#endif