/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:25:49 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/23 14:25:51 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

static void	j_add_1(t_fract *f, t_coord *p, t_coord *c, t_coord *z)
{
	c->x = -0.038088 + f->addx;
	c->y = 0.97 + f->addy;
	z->x = p->x / f->zm.x + f->x1;
	z->y = p->y / f->zm.y + f->y1;
	f->i = 0;
}

static void	j_add_2(double *tmp, t_coord *c, t_coord *z)
{
	*tmp = z->x;
	z->x = z->x * z->x - z->y * z->y + c->x;
	z->y = 2 * z->y * *tmp + c->y;
}

void		julia2(t_fract *f)
{
	double	tmp;
	t_coord p;
	t_coord c;
	t_coord z;

	p.y = f->r.y;
	while (p.y < f->len + f->r.y)
	{
		p.x = f->r.x;
		while (p.x < f->wid + f->r.x)
		{
			j_add_1(f, &p, &c, &z);
			j_add_2(&tmp, &c, &z);
			while (z.x * z.x + z.y * z.y < 4 && f->i < f->imax)
			{
				j_add_2(&tmp, &c, &z);
				f->i++;
			}
			if (f->i > 5 && f->i < f->imax)
				mlx_pixel_image(p.x - f->r.x, p.y - f->r.y, f->i, f);
			p.x++;
		}
		p.y++;
	}
}
