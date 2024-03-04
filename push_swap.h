/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:29:34 by hfiqar            #+#    #+#             */
/*   Updated: 2024/03/04 10:54:21 by hfiqar           ###   ########.fr       */
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
	struct s_list   *prev;
	int             position;
	int             index;
}t_list;

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
int		ft_compt_word(char const *st, char t);
int		ft_compt_chr(char const *str, char r);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		re_place(char **array, const char *tr, char c);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_5args(t_list **a, t_list **b);
int		ft_get_position_small(t_list    *a);
void	ft_3args(t_list **a);
void	ft_get_index(t_list    *a);
void	ft_get_position(t_list  *a);
int		ft_check_sort(t_list	*a);
int		ft_check_dup(t_list	*a);
int		check_empty(char **av);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		somft(char	*str, int i, int sign);
int		ft_atoi(char *str);
t_list	*ft_args(char  **av);
t_list	*norm(char   **argv, int i);
t_list	*ft_lstnew(int	content);
void	ft_free_array(char **array);
void	ft_swap(t_list  **a, char c);
void	ft_push(t_list  **a, t_list  **b, char c, char z);
void	ft_rotate(t_list    **a, char c);
void	ft_re_rotate(t_list **a, char c);
int		find_from_top_bottom(t_list  *a, int i, int j);
void	check_position_moves(t_list **b, t_list **a, int x, int y);
void	algo(t_list **a, t_list **b, int dev);
int		ft_biggest_one(t_list   *b);
void	ft_push_back(t_list **a, t_list **b);

#endif