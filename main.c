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
int main(int ac, char **av)
{
	if (ac > 1)
		ft_error_arg();
	init();
	return (0);
}

int my_key_hook(int keycode, void *param)
{
	printf("coucou\n");
	if(keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

void init(void)
{
	t_env *e;

	if(!(e = (t_env *)malloc(sizeof(t_env))))
		ft_error_malloc();
	e->mlx = mlx_init();
	printf("coucou\n");
	e->win = mlx_new_window(e->mlx, MAP_WIDTH, MAP_HEIGHT, "Fract'ol");
	if(!(e->center = (t_tuple *)malloc(sizeof(t_tuple))))
		ft_error_malloc();
	e->center->x = MAP_WIDTH / 2;
	e->center->y = MAP_HEIGHT / 2;
	e->iteration = 50;
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		ft_error_malloc();
	if (!(e->pas = (t_complex *)malloc(sizeof(t_complex))))
		ft_error_malloc();
	e->img->img = mlx_new_image(e->mlx, MAP_WIDTH, MAP_HEIGHT);
	e->img->data = mlx_get_data_addr(e->img->img, &e->img->bpp, &e->img->size_line, &e->img->endian);
	e->pas->real = 0.01;
	e->pas->imag = 0.01;
	printf("yooo\n");
	go_fractol(e);
	mlx_key_hook(e->win, my_key_hook, e);
	mlx_loop(e->mlx);

}