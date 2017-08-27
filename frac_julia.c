/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:02:42 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/14 21:33:13 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		start_julia(t_pic *image, t_nbr *nbr)
{
	nbr->iterations = 0;
	int	y = -1;
	int	x = -1;
	while (++y <= WIN_Y)
	{
		while (++x <= WIN_X)
		{
			nbr->newRe = (x - WIN_X / 2) / (0.4 * nbr->zoom * WIN_X) + nbr->transX;
			nbr->newIm = (y - WIN_Y / 2) / (0.4 * nbr->zoom * WIN_Y) + nbr->transY;			
			while (++nbr->iterations < nbr->max_iterations && ((nbr->newRe * nbr->newRe) + (nbr->newIm * nbr->newIm) < 4))
			{
				nbr->oldRe = nbr->newRe;
				nbr->oldIm = nbr->newIm;
				nbr->newRe =  ((nbr->oldRe * nbr->oldRe) - (nbr->oldIm * nbr->oldIm)) + nbr->cRe;
				nbr->newIm = (2 * nbr->oldRe * nbr->oldIm) + nbr->cIm;
			}
			put_pixel(x, y, image);
			nbr->iterations = 0;
		}
		x = 0;
	}
}


void		julia(t_env *env)
{
	start_julia(env->image, env->image->nbr);
	mlx_put_image_to_window(env->mlx, env->window, env->image->img_ptr, 0, 0);
	put_directions(env);
	hooks(env);
}
