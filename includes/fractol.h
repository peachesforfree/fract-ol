/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:59:01 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/02 12:10:42 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdio.h>

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"

# define WIN_X 1000
# define WIN_Y 1000
# define ENDN 0
typedef struct	s_nbr
{
	double		cRe;
	double		cIm;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	int			iterations;
	double		zoom;
	double		transX;
	double		transY;
	int			color;
}				t_nbr;

typedef struct	s_pic
{
	void		*img_ptr;
	int			*data;
	int			win_w;
	size_t		*pixel_cnt;
	int			bits_per_pixel;
	int			endian;
	t_nbr		*nbr;
}				t_pic;

typedef struct	s_env
{
	void		*mlx;
	void		*window;
	char		*name;
	int			color;
	int			map_x;
	int			map_y;
	t_pic		*image;
}				t_env;

void			ft_err_memory(char *str);
int 			ft_err_usage(int argc, char **argv);
int				ft_err_input(char *str);
void			julia(t_env *env);
void			*initialize_mlx(char *str);
void			*initialize_image(t_env *env);
void			hooks(t_env *env);
int			motion_hook(int x, int y,t_env *env);
int			key_hook(int keycode, t_env *env);
int				exit_hook(t_env *env);
int			mouse_hooks(int button, int x, int y, t_env *env);
void			start_julia(t_env *env, t_pic *image, t_nbr *nbr);
int				redraw(t_env *env);
void			setting_points(t_nbr *nbr);
void			put_directions(t_env *env);
#endif
