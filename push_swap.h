/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:29:34 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/08 18:33:56 by hfiqar           ###   ########.fr       */
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

#endif 