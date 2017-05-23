/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:37:38 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/23 13:37:41 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

static void	b_add_1(t_fract *f, t_coord *p, t_coord *c, t_coord *z)
{
	c->x = 0.285 + f->addx;
	c->y = 0.01 + f->addy;
	z->x = p->x / f->zm.x + f->x1;
	z->y = p->y / f->zm.y + f->y1;
	f->i = 0;
}

static void	b_add_2(double *tmp, t_coord *c, t_coord *z)
{
	*tmp = z->x;
	z->x = fabs(z->x * z->x - z->y * z->y) + c->x;
	z->y = fabs(2 * z->y * *tmp) + c->y;
}

void		burningship(t_fract *f)
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
			b_add_1(f, &p, &c, &z);
			while (z.x * z.x + z.y * z.y <= 2 && f->i < f->imax)
			{
				b_add_2(&tmp, &c, &z);
				f->i++;
			}
			if (f->i > 5 && f->i < f->imax)
				mlx_pixel_image(p.x - f->r.x, p.y - f->r.y, f->i, f);
			p.x++;
		}
		p.y++;
	}
}
