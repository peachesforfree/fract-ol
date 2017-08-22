/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_attractor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:38:51 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/16 18:57:01 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_complex_number_a(t_nbr *nbr,int x,int y)
{
	nbr->cIm = (x - WIN_X / 2) / (0.5 * (nbr->zoom - .5) * WIN_X) + nbr->transY;
	nbr->cRe = (y - WIN_Y / 2) / (0.5 * (nbr->zoom - .5) * WIN_Y) + nbr->transX;
	nbr->oldRe = 0;
	nbr->oldIm = 0;
	nbr->iterations = 0;
}

void		start_attractor(t_pic *image, t_nbr *nbr)
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
			set_complex_number_a(nbr, col, row);
			while (((nbr->oldRe * nbr->oldRe) + (nbr->oldIm * nbr->oldIm)
			) < 4 && nbr->iterations < nbr->max_iterations)
			{	
				nbr->newRe = (nbr->oldRe * nbr->oldRe) - nbr->oldIm * nbr->oldIm + nbr->cRe;
				nbr->newIm = 2 * (nbr->oldRe * nbr->oldIm - nbr->oldIm) - nbr->cIm;
				nbr->oldRe = nbr->newRe;
				nbr->oldIm = nbr->newIm;
				nbr->iterations++;
			}
			put_pixel(row, col, image);
		}
		col = 0;
	}
}


void	attractor(t_env *env)
{
	start_attractor(env->image, env->image->nbr);
	mlx_put_image_to_window(env->mlx, env->window, env->image->img_ptr, 0, 0);
	put_directions(env);
	hooks(env);
}
