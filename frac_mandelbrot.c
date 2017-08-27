/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:12:20 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/15 18:12:44 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_complex_number(t_nbr *nbr,int x,int y)
{
	nbr->cIm = (x - WIN_X / 2) / (0.3 * nbr->zoom * WIN_X) + nbr->transY;
	nbr->cRe = (y - WIN_Y / 2) / (0.3 * nbr->zoom * WIN_Y) + nbr->transX - .4;
	nbr->oldRe = 0;
	nbr->oldIm = 0;
	nbr->iterations = 0;
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
			while (((nbr->oldRe * nbr->oldRe) + (nbr->oldIm * nbr->oldIm)
			) < 4 && nbr->iterations < nbr->max_iterations)
			{	
				nbr->newRe = (nbr->oldRe * nbr->oldRe) - (
				nbr->oldIm * nbr->oldIm) + nbr->cRe;
				nbr->newIm = 2 * nbr->oldRe * nbr->oldIm + nbr->cIm;
				nbr->oldRe = nbr->newRe;
				nbr->oldIm = nbr->newIm;
				nbr->iterations++;
			}
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
