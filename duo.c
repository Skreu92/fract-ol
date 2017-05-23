/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:47:50 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/23 15:47:52 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int go_duo(char *str1, char *str2)
{
	t_fract *f1;
	t_fract *f2;

	if (!(f1 = (t_fract*)ft_memalloc(sizeof(t_fract))))
		return (-1);
	if (!(f2 = (t_fract*)ft_memalloc(sizeof(t_fract))))
		return (-1);
	f1->bpp = (int*)ft_memalloc(sizeof(int));
	f2->bpp = (int*)ft_memalloc(sizeof(int));
	f1->bpl = (int*)ft_memalloc(sizeof(int));
	f2->bpl = (int*)ft_memalloc(sizeof(int));
	f1->end = (int*)ft_memalloc(sizeof(int));
	f2->end = (int*)ft_memalloc(sizeof(int));
	if (!f1->bpp || !f1->bpl || !f1->end || !f2->bpp || !f2->bpl || !f2->end)
		return (-1);
	f1->mlx = mlx_init();
	f1->win = mlx_new_window(f1->mlx, 1280, 720, "Fract'ol1");
	f1->img = mlx_new_image(f1->mlx, 1280, 720);
	f1->add = (int*)mlx_get_data_addr(f1->img, f1->bpp, f1->bpl, f1->end);
	f2->mlx = mlx_init();
	f2->win = mlx_new_window(f2->mlx, 1280, 720, "Fract'ol2");
	f2->img = mlx_new_image(f2->mlx, 1280, 720);
	f2->add = (int*)mlx_get_data_addr(f2->img, f2->bpp, f2->bpl, f2->end);
	init_fract(f1);
	init(f1, str1);
	init_fract(f2);
	init(f2, str2);
	return (1);
}