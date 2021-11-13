/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <byuri@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:21:30 by byuri             #+#    #+#             */
/*   Updated: 2021/10/06 17:21:30 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_rgbt(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_pix_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

	if (x >= 0 && y >= 0)
	{
		dst = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
		*(unsigned int *)dst = colour;
	}
}

void	colour_pix_mdbr(int n, int x, int y, t_img *img)
{
	int		colour;
	int		r;
	int		g;
	int		b;
	double	xn;

	xn = (double)n / img->max_iter;
	b = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.15) / 0.5));
	g = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.78) / 0.5));
	r = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.67) / 0.5));
	colour = ft_rgbt(0, r, g, b);
	if (n < img->max_iter && n > 0)
		my_pix_put(img, x, y, colour);
	else
		my_pix_put(img, x, y, 0x00);
}

void	colour_pix_jul(int n, int x, int y, t_img *img)
{
	int		colour;
	int		r;
	int		g;
	int		b;
	double	xn;

	xn = (double)n / img->max_iter;
	b = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.85) / 0.5));
	g = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.98) / 0.5));
	r = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.21) / 0.5));
	colour = ft_rgbt(0, r, g, b);
	if (n < img->max_iter && n > 0)
		my_pix_put(img, x, y, colour);
	else
		my_pix_put(img, x, y, 0x00);
}

void	colour_pix_ship(int n, int x, int y, t_img *img)
{
	int		colour;
	int		r;
	int		g;
	int		b;
	double	xn;

	xn = (double)n / img->max_iter;
	g = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.45) / 0.5));
	b = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.18) / 0.5));
	r = (int)(127.5 + 127.5 * sin(M_PI * (xn - 0.21) / 0.5));
	colour = ft_rgbt(0, r, g, b);
	if (n < img->max_iter && n > 0)
		my_pix_put(img, x, y, colour);
	else
		my_pix_put(img, x, y, 0x00);
}
