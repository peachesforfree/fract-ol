/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_fibb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:12:20 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/15 21:27:52 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		start_mandelbrot(t_pic *image, t_nbr *nbr)
{
	int		row;
	int		col;

	nbr->iterations = 0;
	row = 0;
	col = 0;
	while (++row < WIN_Y)
	{
		while (++col < WIN_X)
		{
			set_complex_number(nbr, col, row);
			put_pixel(row, col, image);
		}
		col = 0;
	}
}

void		mandelbrot(t_env *env)
{
	start_mandelbrot(env->image, env->image->nbr);
	mlx_put_image_to_window(env->mlx, env->window, env->image->img_ptr, 0, 0);
	put_directions(env);
	hooks(env);
}
