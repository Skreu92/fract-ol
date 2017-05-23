/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:40:31 by Etienne           #+#    #+#             */
/*   Updated: 2017/05/21 18:40:36 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int		keymove(int keycode, t_fract *f)
{
	if (keycode == 124)
		f->mv.x = f->mv.x + 40 / f->zoom;
	if (keycode == 123)
		f->mv.x = f->mv.x - 40 / f->zoom;
	if (keycode == 125)
		f->mv.y = f->mv.y + 40 / f->zoom;
	if (keycode == 126)
		f->mv.y = f->mv.y - 40 / f->zoom;
	return (0);
}

int		keyzoom(int keycode, t_fract *f)
{
	if (keycode == 7)
	{
		init_fract(f);
		init(f, f->arg);
		return (0);
	}
	if (keycode == 69 && f->zoom * 1.10 < 2148473647)
		f->zoom = f->zoom * 1.10;
	if (keycode == 78)
		f->zoom = f->zoom * 0.90;
	if (f->zoom < 1)
		f->zoom = 1;
	return (0);
}

int		keyimax(int keycode, t_fract *f)
{
	if (keycode == 116 && f->imax < 400)
		f->imax = f->imax + 10;
	if (keycode == 121)
		f->imax = f->imax - 10;
	if (f->imax < 10)
		f->imax = 10;
	return (0);
}

int		keycolor(int keycode, t_fract *f)
{
	if (keycode == 75 || keycode == 67)
	{
		if (keycode == 75)
			f->col = f->col * 1 + 0xFFFFFF / 4;
		if (keycode == 67)
			f->col = f->col * 1 + 0xFFFFFF / 4;
		if (f->col < 0)
			f->col = 0x00FFFFFF;
		if (f->col > 0x00FFFFFF)
			f->col = 255;
	}
	else
		init_fract(f);
	return (0);
}

int		init_key(int keycode, void *param)
{
	t_fract *f;

	f = (t_fract*)param;
	printf("key%d\n", keycode);
	mlx_clear_window(f->mlx, f->win);
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, 1280, 720);
	if (keycode == 53)
		exit(-1);
	if (keycode >= 123 && keycode <= 126)
		keymove(keycode, f);
	if (keycode == 69 || keycode == 78 || keycode == 7)
		keyzoom(keycode, f);
	if (keycode == 116 || keycode == 121)
		keyimax(keycode, f);
	if (keycode == 75 || keycode == 67 || keycode == 82)
		keycolor(keycode, f);
	if (keycode == 4)
		f->help = (f->help == 1) ? 0 : 1;
	f->r.x = fabs(f->wid / 2 - (f->wid / 2 * f->zoom)) + f->mv.x * f->zoom;
	f->r.y = fabs(f->len / 2 - (f->len / 2 * f->zoom)) + f->mv.y * f->zoom;
	f->zm.x = (f->wid * f->zoom) / (f->x2 - f->x1);
	f->zm.y = (f->len * f->zoom) / (f->y2 - f->y1);
	init(f, f->arg);
	return (0);
}
