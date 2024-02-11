/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:29:34 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/11 14:59:58 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include<stdlib.h>
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
int	re_place(char **array, const char *tr, char c);
char	**ft_split(char const *s, char c);
char	**ft_strjoin(char const *s1, char const *s2);

#endif 