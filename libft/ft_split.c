/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <byuri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:32:50 by byuri             #+#    #+#             */
/*   Updated: 2021/10/09 14:36:32 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_c(char *str, char c)
{
	char	*b;
	int		count;

	b = str;
	count = 0;
	while (*b)
	{
		while (*b && *b == c)
			b++;
		if (*b && *b != c)
		{
			count++;
			while (*b && *b != c)
				b++;
		}
	}
	return (count);
}

static char	*ft_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

static char	**ft_malloc_er(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (NULL);
}

static char	**ft_puts(char *str, char **a, char c)
{
	int		i;
	int		j;
	char	*b;

	i = 0;
	while (*str)
	{
		j = 0;
		while (*str && *str == c)
			str++;
		while (*(str + j) && *(str + j) != c)
			j++;
		if (*str && *str != c)
		{
			b = (char *) malloc(sizeof(char) * (j + 1));
			if (!b)
				return (ft_malloc_er(a));
			ft_strncpy(b, str, j);
			a[i++] = b;
			while (*str && *str != c)
				str++;
		}
	}
	a[i] = (void *)0;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		n;

	if (!s)
		return ((void *)0);
	n = ft_word_c((char *)s, c);
	a = (char **) malloc(sizeof(char *) * (n + 1));
	if (!a)
		return (NULL);
	a = ft_puts((char *)s, a, c);
	return (a);
}
