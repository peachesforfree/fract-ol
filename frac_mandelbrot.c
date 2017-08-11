/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:12:20 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/11 13:01:17 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void		set_complex_number(t_nbr *nbr,int x,int y)
{
	nbr->cIm = (x - WIN_X / 2) / (0.5 * nbr->zoom * WIN_X) + nbr->transY;
	nbr->cRe = (y - WIN_Y / 2) / (0.5 * nbr->zoom * WIN_Y) + nbr->transX;
}

void		put_pixel(int x, int y, t_pic *image)
{
	int place;
	int color;

	if (image->nbr->color_rot != 0)
		image->nbr->color_rot += 1;
	color = 16711680 + (image->nbr->iterations * 14080) + image->nbr->color_rot;
	if (image->nbr->iterations == image->nbr->max_iterations)
		color = 0;
	place = x + ((y - 1) * WIN_X);
	image->data[place] = color;
}

void		debugging(t_env *env)
{
	int x = -1;
	int y = -1;
	while (++x < WIN_X)
			put_pixel(x, (WIN_Y / 2), env->image);
	while (++y < WIN_Y)
			put_pixel((WIN_X / 2), y, env->image);	
}

void		start_mandelbrot(t_env *env, t_pic *image, t_nbr *nbr)
{
	void *dump;
	double temp;
	double x;
	double y;
	int		row;
	int		col;
	
	dump = (void*)env;
	x = -1;
	y = -1;
	nbr->iterations = 0;
	row = 0;
	col = 0;
	while (++row < WIN_Y)
	{
		while (++col < WIN_X)
		{
			set_complex_number(nbr, col, row);
			x = 0;
			y = 0;	
			while (((x * x) + (y * y)) < 4 && nbr->iterations < nbr->max_iterations)
			{	
				temp = (x * x) - (y * y) + nbr->cRe;
				y = 2 * x * y + nbr->cIm;
				x = temp;
				nbr->iterations++;
			}
			put_pixel(row, col, image);
			nbr->iterations = 0;
		}
		col = 0;
	}
	debugging(env);
}

void		mandelbrot(t_env *env)
{
	start_mandelbrot(env, env->image, env->image->nbr);
	mlx_put_image_to_window(env->mlx, env->window, env->image->img_ptr, 0, 0);
	put_directions(env);
	hooks(env);
}
