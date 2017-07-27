/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:59:01 by sbalcort          #+#    #+#             */
/*   Updated: 2017/07/26 17:33:39 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"

# define WIN_X 1500
# define WIN_Y 100

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
	void		*image;
	size_t		*pixel_cnt;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_nbr		*nbr;
}				t_pic;

typedef struct	s_env
{
	void		*mlx;
	void		*window;
	int			color;
	int			map_x;
	int			map_y;
	t_pic		*image;
}				t_env;

void			ft_err_memory(char *str);
int 			ft_err_usage(int argc, char **argv);
int				ft_err_input(char *str);
void			julia(void);
void			*initialize_mlx(char *str);
void			*initialize_image(t_env *env);
#endif
