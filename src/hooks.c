/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byuri <byuri@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:20:44 by byuri             #+#    #+#             */
/*   Updated: 2021/10/06 17:20:44 by byuri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key_code, t_sess *curr)
{
	t_img	*img;

	img = curr->image;
	if (key_code == MAIN_PAD_ESC)
		exit(1);
	if (key_code == ARROW_LEFT)
		img->start_x -= (0.15 * img->zoom);
	if (key_code == ARROW_RIGHT)
		img->start_x += (0.15 * img->zoom);
	if (key_code == ARROW_DOWN)
		img->start_y += (0.15 * img->zoom);
	if (key_code == ARROW_UP)
		img->start_y -= (0.15 * img->zoom);
	draw_fractal(curr, img->start_y, img->start_x, img->zoom);
	mlx_put_image_to_window(curr->mlx_ptr, curr->win_ptr, img->img, 0, 0);
	return (0);
}

int	zoom(int button, int x, int y, t_sess *curr)
{
	t_img	*image;
	double	new_x;
	double	new_y;

	image = curr->image;
	if (button == MOUSE_SCROLL_DOWN)
	{
		new_x = (image->zoom * ((double)x / curr->width)) + image->start_x;
		new_y = (image->zoom * ((double)y / curr->height)) + image->start_y;
		image->start_x = new_x - (image->zoom / 2) * 0.35;
		image->start_y = new_y - (image->zoom / 2) * 0.35;
		image->zoom *= 0.75;
		image->max_iter = (int)(image->max_iter * 1.05);
	}
	if (button == MOUSE_SCROLL_UP)
	{
		image->start_x -= (image->zoom / 2);
		image->start_y -= (image->zoom / 2);
		image->zoom /= 0.75;
		image->max_iter = (int)(image->max_iter / 1.05);
	}
	draw_fractal(curr, image->start_y, image->start_x, image->zoom);
	mlx_put_image_to_window(curr->mlx_ptr, curr->win_ptr, image->img, 0, 0);
	return (0);
}

int	julia_const(int x, int y, t_sess *curr)
{
	t_img	*image;
	double	new_x;
	double	new_y;

	if (curr->type == 2)
	{
		image = curr->image;
		new_x = (image->zoom * ((double)x / curr->width)) + image->start_x;
		new_y = (image->zoom * ((double)y / curr->height)) + image->start_y;
		(image->constant)[0] = new_x;
		(image->constant)[1] = new_y;
		draw_fractal(curr, image->start_y, image->start_x, image->zoom);
		mlx_put_image_to_window(curr->mlx_ptr, curr->win_ptr, image->img, 0, 0);
	}
	return (0);
}

int	colour_shift(int key_code, t_sess *curr)
{
	void	(*col_f[3])(int, int, int, t_img*);
	t_img	*img;

	img = curr->image;
	col_f[0] = colour_pix_mdbr;
	col_f[1] = colour_pix_jul;
	col_f[2] = colour_pix_ship;
	if (key_code == MAIN_PAD_SHIFT)
	{
		curr->col_f = col_f[curr->counter % 3];
		curr->counter++;
		draw_fractal(curr, img->start_y, img->start_x, img->zoom);
		mlx_put_image_to_window(curr->mlx_ptr, curr->win_ptr, img->img, 0, 0);
	}
	return (0);
}
