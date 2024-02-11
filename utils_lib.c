/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:35:24 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/11 15:00:54 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_compt_word(char const *st, char t)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (st[i])
	{
		while (st[i] && st[i] == t)
			i++;
		while (st[i] && st[i] != t)
			i++;
		cnt++;
	}
	if (!st[0])
		return (0);
	if (st[ft_strlen((char *)st) - 1] == t)
		cnt = cnt -1;
	return (cnt);
}

int	ft_compt_chr(char const *str, char r)
{
	int	j;

	j = 0;
	while (*str && *str == r)
		str++;
	while (*str && *str != r)
	{
		str++;
		j++;
	}
	return (j);
}

int	re_place(char **array, const char *tr, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (i < ft_compt_word(tr, c))
	{
		array[i] = malloc(ft_compt_chr(tr + x, c) + 1);
		if (!array[i])
		{
			while (--i >= 0)
				free (array[i]);
			free(array);
			return (1);
		}
		j = 0;
		while (tr[x] == c)
			x++;
		while (tr[x] && tr[x] != c)
			array[i][j++] = tr[x++];
		array[i++][j] = '\0';
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**array;

	if (s == NULL )
		return (NULL);
	cnt = ft_compt_word(s, c);
	array = malloc (sizeof(char *) * (cnt +1));
	if (!array)
		return (NULL);
	if (re_place(array, s, c))
		return (NULL);
	array[cnt] = NULL;
	return (array);
}

char	**ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}
