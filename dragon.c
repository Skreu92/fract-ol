/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:02:06 by Etienne           #+#    #+#             */
/*   Updated: 2017/05/21 19:02:08 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

static void	d_add_1(t_fract *f, t_coord *p, t_coord *c, t_coord *z)
{
	c->x = 0.285 + f->addx;
	c->y = f->addy;
	z->x = p->x / f->zm.x + f->x1;
	z->y = p->y / f->zm.y + f->y1;
	f->i = 0;
}

static void	d_add_2(double *tmp, t_coord *c, t_coord *z)
{
	*tmp = z->x;
	z->x = z->x * z->x - z->y * z->y + c->x;
	z->y = 4 * z->y * *tmp + c->y;
}

void		dragonbrot(t_fract *f)
{
	double	tmp;
	t_coord	p;
	t_coord	c;
	t_coord	z;

	p.y = f->r.y;
	while (p.y < f->len + f->r.y)
	{
		p.x = f->r.x;
		while (p.x < f->wid + f->r.x)
		{
			d_add_1(f, &p, &c, &z);
			d_add_2(&tmp, &c, &z);
			while (z.x * z.x + z.y * z.y < 4 && f->i < f->imax)
			{
				d_add_2(&tmp, &c, &z);
				f->i++;
			}
			if (f->i > 5 && f->i < f->imax)
				mlx_pixel_image(p.x - f->r.x, p.y - f->r.y, f->i, f);
			p.x++;
		}
		p.y++;
	}
}
