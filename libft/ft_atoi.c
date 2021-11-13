#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	s;
	int	sing;

	nbr = 0;
	s = 0;
	sing = 1;
	while ((str[s] == ' ') || (str[s] >= 9 && str[s] <= 13))
		s++;
	if (str[s] == '-' || str[s] == '+')
	{
		if (str[s] == '-')
			sing = -sing;
		s++;
	}
	while (str[s] >= '0' && str[s] <= '9')
	{
		nbr = nbr * 10 + (str[s] - '0');
		s++;
	}
	return (sing * nbr);
}
