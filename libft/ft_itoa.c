/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <byuri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:34:04 by byuri             #+#    #+#             */
/*   Updated: 2021/10/09 14:36:32 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenn(int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*res;
	size_t		s;
	size_t		lens;
	long long	num;

	num = n;
	s = (n < 0);
	lens = lenn(num);
	if (num < 0)
		num = -num;
	res = malloc(sizeof(char) * (lens + s + 1));
	if (!res)
		return (0);
	res[lens + s] = '\0';
	if (s)
		res[0] = '-';
	while (lens--)
	{
		res[lens + s] = (num % 10 + '0');
		num = num / 10;
	}
	return (res);
}
