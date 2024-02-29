/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:42:07 by hfiqar            #+#    #+#             */
/*   Updated: 2024/02/29 23:42:20 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *s)
{
	size_t		len ;
	char		*str;
	int			i;

	i = 0;
	len = ft_strlen((char *)s);
	str = malloc(len +1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
    if (s2 == NULL)
        return (ft_strdup(s1));
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
