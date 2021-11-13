/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <byuri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:32:13 by byuri             #+#    #+#             */
/*   Updated: 2021/10/09 14:36:32 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*src;
	unsigned int	i;

	src = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	i = 0;
	if (!src)
		return (NULL);
	while (s[i] != '\0')
	{
		src[i] = (*f)(i, s[i]);
		i++;
	}
	src[i] = '\0';
	return (src);
}
