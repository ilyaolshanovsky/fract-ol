/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <byuri@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:22:20 by byuri             #+#    #+#             */
/*   Updated: 2021/10/08 15:44:36 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_exit(void)
{
	printf("Параметры для множества Жулиа должны быть числовыми:\n"
		   "реальная часть и мнимая часть\n");
	exit(1);
}

int	check_args(int argc, char **argv)
{
	char	*mdbr;
	char	*jul;
	char	*ship;

	mdbr = "Mandelbrot";
	jul = "Julia";
	ship = "BurningShip";
	if (argc > 1 && !ft_strncmp(argv[1], mdbr, ft_strlen(mdbr)))
		return (1);
	else if (argc > 1 && !ft_strncmp(argv[1], jul, ft_strlen(jul)))
		return (2);
	else if (argc > 1 && !ft_strncmp(argv[1], ship, ft_strlen(ship)))
		return (3);
	else
	{
		printf("\nВыбери желаемый фрактал: \n%s \n%s \n%s \n \n", mdbr,
			   jul, ship);
		exit(1);
	}
}

void	initialize_param(t_param *alt)
{
	alt->fact = 1.0;
	alt->p = 0;
	alt->res = 0.0;
	alt->num = 0;
}

double	ft_param(char *s)
{
	t_param	alt;

	initialize_param(&alt);
	if (*s == '-')
	{
		s++;
		alt.fact = -1;
	}
	while (*s)
	{
		if (*s == '.')
		{
			alt.p++;
			s++;
			continue ;
		}
		if (alt.p)
			alt.fact /= 10.0;
		if (*s && ((alt.p > 1 && *s == '.') || (!ft_isdigit(*s) && *s != '.')))
			error_exit();
		alt.num = *s - '0';
		alt.res = alt.res * 10.0 + (double)alt.num;
		s++;
	}
	return (alt.res * alt.fact);
}

void	check_jul_params(char **argv, t_img *image)
{
	image->constant[0] = ft_param(argv[2]);
	image->constant[1] = ft_param(argv[3]);
}
