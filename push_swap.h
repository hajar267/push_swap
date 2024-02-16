/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:29:34 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/16 18:44:22 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include <unistd.h>
#ifndef NULL
#include <sys/_types.h>
#define NULL   __DARWIN_NULL
#endif

typedef struct s_list
{
    int             data;
    struct s_list   *next;
}t_list;

int	ft_compt_word(char const *st, char t);
int	ft_compt_chr(char const *str, char r);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
t_list    *ft_args(char  **av);
int	somft(char	*str, int i, int sign);
int	ft_atoi(char *str);
t_list  **place(char  **av);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_check_dup(t_list *a);
int	ft_check_dup_int(t_list	*a);
void    ft_swap(t_list  **a);
void    ft_push(t_list  **a, t_list  **b);
void    ft_rotate(t_list    **a);
t_list	*ft_lstlast(t_list *lst);
void    ft_re_rotate(t_list **a);
void    ft_3args(t_list **a);

#endif