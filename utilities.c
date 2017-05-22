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
	return (0);
}

int		put_details_2(t_fract *f)
{
	char	*tmp[4];

	tmp[0] = ft_itoa(f->zoom);
	tmp[1] = ft_itoa(f->imax);
	mlx_string_put(f->mlx, f->win, 10, 10, 0xFFFFFF, "Zoom :");
	mlx_string_put(f->mlx, f->win, 10, 30, 0xFFFFFF, "Iteration :");
	mlx_string_put(f->mlx, f->win, 130, 10, 0xFFFFFF, tmp[0]);
	mlx_string_put(f->mlx, f->win, 130, 30, 0xFFFFFF, tmp[1]);
	ft_memdel((void**)&tmp[0]);
	ft_memdel((void**)&tmp[1]);
	ft_memdel((void**)&tmp);
	return (0);
}

int		put_details(t_fract *f)
{
	int x;
	int y;

	y = 0;
	while (y < 65)
	{
		x = 0;
		while (x < 280)
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