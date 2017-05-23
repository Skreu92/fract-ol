/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:58:28 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/15 19:58:29 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include <stdio.h>

int		leave_window(void)
{
	exit(-1);
	return (0);
}

int		att_coord_mouse(int x, int y, void *param)
{
	t_fract *f;

	f = (t_fract*)param;
	if (x >= 0 && x <= f->wid && y >= 0 && y <= f->len && f->zoom == 1)
	{
		f->addx = (double)((x - 640) * 0.0001);
		f->addy = (double)((y - 360) * 0.0001);
		mlx_clear_window(f->mlx, f->win);
		mlx_destroy_image(f->mlx, f->img);
		f->img = mlx_new_image(f->mlx, 1280, 720);
		init(f, f->arg);
	}
	return (0);
}

int		init_fract(t_fract *f)
{
	f->wid = 1280;
	f->len = 720;
	f->zoom = 1;
	f->imax = 40;
	f->mv.x = 0;
	f->mv.y = 0;
	f->x1 = -2.1;
	f->x2 = 2.1;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->zm.x = (f->wid * f->zoom) / (f->x2 - f->x1);
	f->zm.y = (f->len * f->zoom) / (f->y2 - f->y1);
	f->r.x = 0;
	f->r.y = 0;
	f->addx = 0;
	f->addy = 0;
	f->col = 0xFFFF00;
	f->help = 0;
	return (0);
}

int		init(t_fract *f, char *argv)
{
	if (!(ft_strcmp(argv, "-j") && ft_strcmp(argv, "-m")
		&& ft_strcmp(argv, "-d") && ft_strcmp(argv, "-b")
		&& ft_strcmp(argv, "-j2")
		&& ft_strcmp(argv, "-j3")))
	{
		launch_frac(f, argv);
		mlx_key_hook(f->win, init_key, f);
		mlx_mouse_hook(f->win, init_mouse, f);
		mlx_hook(f->win, 6, 6, att_coord_mouse, f);
		mlx_hook(f->win, 17, 17, leave_window, f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		if (f->help == 1)
			put_details(f);
		mlx_loop(f->mlx);
		return (1);
	}
	else
	{
		error_usage();
		return (0);
	}
}

int		main(int argc, char **argv)
{
	t_fract *f;

	f = NULL;
	if (argc == 2 && check_arg_enter(argv[1]))
	{
		printf("coucoa\n");
		if (!(f = (t_fract*)ft_memalloc(sizeof(t_fract))))
			return (-1);
		f->bpp = (int*)ft_memalloc(sizeof(int));
		f->bpl = (int*)ft_memalloc(sizeof(int));
		f->end = (int*)ft_memalloc(sizeof(int));
		if (!f->bpp || !f->bpl || !f->end)
			return (-1);
		f->mlx = mlx_init();
		f->win = mlx_new_window(f->mlx, 1280, 720, "Fract'ol");
		f->img = mlx_new_image(f->mlx, 1280, 720);
		f->add = (int*)mlx_get_data_addr(f->img, f->bpp, f->bpl, f->end);
		init_fract(f);
		init(f, argv[1]);
	}
	else
		error_usage();
	return (0);
}
