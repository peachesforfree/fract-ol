/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandel5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 17:46:08 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/16 18:32:15 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_complex_bulb(t_nbr *nbr,int x,int y)
{
	nbr->cIm = (x - WIN_X / 2) / (0.5 * nbr->zoom * WIN_X) + nbr->transY;
	nbr->cRe = (y - WIN_Y / 2) / (0.5 * nbr->zoom * WIN_Y) + nbr->transX;
	nbr->oldRe = 0;
	nbr->oldIm = 0;
	nbr->iterations = 0;
	nbr->max_iterations = 39;
}

void		start_mandel5(t_pic *image, t_nbr *nbr)
{
	int		row;
	int		col;
	
	row = 0;
	col = 0;
	while (++row < WIN_Y)
	{
		while (++col < WIN_X)
		{
			set_complex_bulb(nbr, col, row);
			while (((nbr->oldRe * nbr->oldRe) + (nbr->oldIm * nbr->oldIm)) < 4 && nbr->iterations < nbr->max_iterations)
			{	
				nbr->newRe = pow(nbr->oldRe, 5) - (10 * pow(nbr->oldRe, 3) * pow(nbr->oldIm, 2)) + (5 * nbr->oldRe * pow(nbr->oldIm, 4)) + nbr->cRe;
				nbr->newIm = (5 * pow(nbr->oldRe, 4) * nbr->oldIm) - (10 * pow(nbr->oldIm, 2) * pow(nbr->oldIm, 3)) + pow(nbr->oldIm, 5) + nbr->cIm;
				nbr->oldRe = nbr->newRe;
				nbr->oldIm = nbr->newIm;
				nbr->iterations++;
			}
			if (nbr->iterations < nbr->max_iterations)
				image->data[col + ((row - 1) * WIN_X)] = nbr->iterations * 526344;
			else
				image->data[col + ((row - 1) * WIN_X)] = nbr->iterations * 526344;
		}
		col = 0;
	}
}

void		mandel5(t_env *env)
{
	start_mandel5(env->image, env->image->nbr);
	mlx_put_image_to_window(env->mlx, env->window, env->image->img_ptr, 0, 0);
	put_directions(env);
	hooks(env);
}
