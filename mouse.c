/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:42:40 by Etienne           #+#    #+#             */
/*   Updated: 2017/05/21 18:42:43 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int		mousezoom(int but, int x, int y, t_fract *f)
{
	if (but == 4 && f->zoom * 1.10 < 2148473647)
		f->zoom = f->zoom * 1.10;
	if (but == 5)
		f->zoom = f->zoom * 0.90;
	if (f->zoom < 1)
		f->zoom = 1;
	f->mv.x = f->mv.x + ((x - f->wid / 2) / f->zoom);
	f->mv.y = f->mv.y + ((y - f->len / 2) / f->zoom);
	return (0);
}

int		mouseswitch(t_fract *f)
{
	if (ft_strcmp(f->arg, "-j") == 0)
		f->arg = "-m";
	else if (ft_strcmp(f->arg, "-m") == 0)
		f->arg = "-d";
	else if (ft_strcmp(f->arg, "-d") == 0)
		f->arg = "-j";
	return (0);
}

int		init_mouse(int but, int x, int y, void *param)
{
	t_fract	*f;

	f = (t_fract*)param;
	if (x >= 0 && x <= f->wid && y >= 0 && y <= f->len)
	{
		mlx_clear_window(f->mlx, f->win);
		mlx_destroy_image(f->mlx, f->img);
		f->img = mlx_new_image(f->mlx, 1280, 720);
		if (but == 4 || but == 5)
			mousezoom(but, x, y, f);
		if (but == 1)
			mouseswitch(f);
	}
	f->r.x = fabs(f->wid / 2 - (f->wid / 2 * f->zoom)) + f->mv.x * f->zoom;
	f->r.y = fabs(f->len / 2 - (f->len / 2 * f->zoom)) + f->mv.y * f->zoom;
	f->zm.x = (f->wid * f->zoom) / (f->x2 - f->x1);
	f->zm.y = (f->len * f->zoom) / (f->y2 - f->y1);
	init(f, f->arg);
	return (0);
}