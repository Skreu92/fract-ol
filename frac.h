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
# include "libft/libft.h"
# include "minlibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define MAP_WIDTH 2000
# define MAP_HEIGHT 1000

# define KEY_ESCAPE 53

# define COULEUR [0x000000, 0xFF0000, 0x00FF00, 0x0000FF]
# define ABS(x) ((x > 0) ? (x) : (-x))

typedef struct	s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct	s_fract
{
	void		*mlx;
	void		*win;
	void		*img;

	char		*arg;

	int			len;
	int			wid;

	t_coord		r;
	t_coord		mv;

	double		addx;
	double		addy;

	double		zoom;
	t_coord		zm;

	int			imax;
	int			i;

	int			col;

	double		x1;
	double		x2;
	double		y1;
	double		y2;

	int			help;

	int			*add;
	int			*bpp;
	int			*bpl;
	int			*end;
}				t_fract;

int				check_arg_enter(char *argv);
int 			check_arg_enter(char *argv);
int				leave_window(void);
int				init(t_fract *f, char *argv);
int				init_fract(t_fract *f);
int				mlx_pixel_image(int x, int y, int i, t_fract *f);
int				error_usage(void);
int				put_details(t_fract *f);
int				put_details_2(t_fract *f);
int				init_key(int keycode, void *param);
int				init_mouse(int but, int x, int y, void *param);
void			julia(t_fract *f);
void			mandelbrot(t_fract *f);
void			dragonbrot(t_fract *f);
void			burningship(t_fract *f);
void			julia2(t_fract *f);
void			julia3(t_fract *f);
void			launch_frac(t_fract *f, char *argv);

#endif
