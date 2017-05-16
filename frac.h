/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 20:00:59 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/15 20:01:01 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H
#include "libft/libft.h"
#include "minlibx/mlx.h"
#include <math.h>


# define MAP_WIDTH 2000
# define MAP_HEIGHT 1000

# define KEY_ESCAPE 53

# define COULEUR [0x000000, 0xFF0000, 0x00FF00, 0x0000FF]
# define ABS(x) ((x > 0) ? (x) : (-x))

typedef struct s_tuple
{
	float x;
	float y;
}				t_tuple;

typedef struct s_complex
{
	float real;
	float imag;
}				t_complex;

typedef struct s_color
{
	char rgb[4];
}				t_color;

typedef struct s_img
{
	void *img;
	char *data;
	int bpp;
	int endian;
	int size_line;
}				t_img;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_tuple		*center;
	t_complex	*pas;
	int iteration;
}				t_env;


t_color put_rgb(char r, char g, char b);
void put_color_to_img(t_img *img, int x, int y, t_color rgb);
int go_to_px(t_env *e, t_complex *center, int x, int y, t_complex *complex);
void init(void);
void ft_error_arg(void);
void ft_error_malloc(void);
void go_fractol(t_env *e);
float power2(float x);
t_color go_color(int i, float d);
float module(t_complex z);

#endif
