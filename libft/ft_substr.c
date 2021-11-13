/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <byuri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:31:46 by byuri             #+#    #+#             */
/*   Updated: 2021/10/09 14:36:32 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mini(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*dst_s;
	size_t	alen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	alen = ft_mini(len, ft_strlen(s) - start);
	dst = (char *)malloc(sizeof(char) * alen + 1);
	if (!dst)
		return (NULL);
	dst_s = dst;
	dst[alen] = '\0';
	while (s[start] && alen--)
		*dst++ = s[start++];
	return (dst_s);
}
