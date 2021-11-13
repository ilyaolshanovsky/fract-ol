/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <byuri@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:21:38 by byuri             #+#    #+#             */
/*   Updated: 2021/10/08 15:26:22 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_sess *win, double ymin, double xmin, double zoom)
{
	int		y_idx;
	int		x_idx;
	t_point	point;
	int		n;

	point.dx = zoom / win->width;
	point.dy = zoom / win->height;
	point.y = ymin;
	y_idx = 0;
	while (y_idx < win->height)
	{
		x_idx = 0;
		point.x = xmin;
		while (x_idx < win->width)
		{
			n = win->iter_f(point.x, point.y, win->image);
			win->col_f(n, x_idx, y_idx, win->image);
			point.x += point.dx;
			x_idx++;
		}
		point.y += point.dy;
		y_idx++;
	}
}

int	iterate_mdbr(double a, double b, t_img *img)
{
	int		n;
	double	new_a;
	double	new_b;
	double	ca;
	double	cb;

	n = 0;
	ca = a;
	cb = b;
	while (n < img->max_iter && (a * a + b * b < 4.0))
	{
		new_a = (a * a) - (b * b);
		new_b = 2.0 * a * b;
		a = new_a + ca;
		b = new_b + cb;
		n++;
	}
	return (n);
}

int	iterate_ship(double a, double b, t_img *img)
{
	int		n;
	double	new_a;
	double	new_b;
	double	ca;
	double	cb;

	n = 0;
	ca = a;
	cb = b;
	while (n < img->max_iter && (a * a + b * b < 4.0))
	{
		new_a = (a * a) - (b * b);
		new_b = 2.0 * a * b;
		if (new_b < 0)
			new_b *= (-1);
		a = new_a - ca;
		b = new_b + cb;
		n++;
	}
	return (n);
}

int	iterate_jul(double a, double b, t_img *img)
{
	int		n;
	double	new_a;
	double	new_b;
	double	ca;
	double	cb;

	n = 0;
	ca = (img->constant)[0];
	cb = (img->constant)[1];
	while (n < img->max_iter && (a * a + b * b < 4.0))
	{
		new_a = (a * a) - (b * b);
		new_b = 2.0 * a * b;
		a = new_a + ca;
		b = new_b + cb;
		n++;
	}
	return (n);
}
