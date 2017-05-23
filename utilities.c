/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 00:10:11 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/16 00:10:12 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int		mlx_pixel_image(int x, int y, int i, t_fract *f)
{
	if (y > 0 && x > 0 && y < f->len && x < f->wid)
		f->add[y * f->wid + x] = f->col + (i * f->col / 20);
	return (0);
}

int		error_usage(void)
{
	ft_putstr("usage : ./fractol <option>\n");
	ft_putstr("   -j\tJulia\n");
	ft_putstr("   -m\tMandelbrot\n");
	ft_putstr("   -d\tDragonbrot\n");
	ft_putstr("   -b\tBurningship\n");
	ft_putstr("   -j2\tJuliav2\n");
	ft_putstr("   -j3\tJuliav3\n");
	leave_window();
	return (0);
}

int		put_details_2(t_fract *f)
{
	char	*tmp[4];

	tmp[0] = ft_itoa(f->zoom);
	tmp[1] = ft_itoa(f->imax);
	mlx_string_put(f->mlx, f->win, 10, 10, 0xFFFFFF, "Change Zoom  : + or -");
	mlx_string_put(f->mlx, f->win, 10, 30, 0xFFFFFF, "Iteration    : PU or PD");
	mlx_string_put(f->mlx, f->win, 10, 50, 0xFFFFFF, "Reset        : x");
	mlx_string_put(f->mlx, f->win, 10, 70, 0xFFFFFF, "Move         : u / d / l / r");
	mlx_string_put(f->mlx, f->win, 10, 90, 0xFFFFFF, "Change color : * or /");
	mlx_string_put(f->mlx, f->win, 10, 110, 0xFFFFFF, "Quit         : ESC");
	ft_memdel((void**)&tmp[1]);
	ft_memdel((void**)&tmp);
	return (0);
}

int		put_details(t_fract *f)
{
	int x;
	int y;

	y = 0;
	while (y < 150)
	{
		x = 0;
		while (x < 320)
		{
			if (y != 64 || x != 279)
				mlx_pixel_put(f->mlx, f->win, x, y, 0xAAFFFFFF);
			x++;
		}
		y++;
	}
	put_details_2(f);
	return (0);
}

void	launch_frac(t_fract *f, char *argv)
{
	f->arg = argv;
	if (ft_strcmp(argv, "-j") == 0)
		julia(f);
	if (ft_strcmp(argv, "-j2") == 0)
		julia2(f);
	if (ft_strcmp(argv, "-j3") == 0)
		julia3(f);
	if (ft_strcmp(argv, "-m") == 0)
		mandelbrot(f);
	if (ft_strcmp(argv, "-d") == 0)
		dragonbrot(f);
	if (ft_strcmp(argv, "-b") == 0)
		burningship(f);
}
