/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 22:30:15 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/15 22:30:16 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void go_fractol(t_env *e)
{
	t_complex *julia;
	int x;
	int y;

	julia->real = -0.7927;
	julia->imag = 0.1609;
	x = 0;
	while (x < MAP_WIDTH)
	{
		y = 0;
		while (y < MAP_HEIGHT)
		{
			go_to_px(e, e->center, x ,y);
		}
		x++;
	}
}

void go_to_px(t_env *e, t_tuple *center, int x, int y)
{
	int real_x;
	int real_y;

	real_x = x - center->x;
	real_y = y - center->y;
	
}
