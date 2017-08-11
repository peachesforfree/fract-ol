/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:12:20 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/08 21:45:38 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void		set_complex_number(t_nbr *nbr,int x,int y)
{
	nbr->cIm = (x - WIN_X / 2) / (0.5 * nbr->zoom * WIN_X) + nbr->transY;
	nbr->cRe = (y - WIN_Y / 2) / (0.5 * nbr->zoom * WIN_Y) + nbr->transX;
}

void		put_pixel(int x, int y, int color, t_pic *image)
{
	int place;

	color = 16711680 + (color * 14080);
	if (color == image->nbr->iterations)
		color = 0;
	place = x + ((y - 1) * WIN_X);
	image->data[place] = color;
}

void		start_mandelbrot(t_env *env, t_pic *image, t_nbr *nbr)
{
	void *dump;
	double temp;
	double x;
	double y;
	int		row;
	int		col;
	int i;
	
	dump = (void*)env;
	x = -1;
	y = -1;
	i = 0;
	row = 0;
	col = 0;
	while (++row < WIN_Y)
	{
		while (++col < WIN_X)
		{
			set_complex_number(nbr, col, row);
			x = 0;
			y = 0;	
			while (((x * x) + (y * y)) < 4 && i < nbr->iterations)
			{	
				temp = (x * x) - (y * y) + nbr->cRe;
				y = 2 * x * y + nbr->cIm;
				x = temp;
				i++;
			}
			put_pixel(row, col, i, image);
			i = 0;
		}
		col = 0;
	}
}

void		mandelbrot(t_env *env)
{
	start_mandelbrot(env, env->image, env->image->nbr);
	mlx_put_image_to_window(env->mlx, env->window, env->image->img_ptr, 0, 0);
	put_directions(env);
	hooks(env);
}
