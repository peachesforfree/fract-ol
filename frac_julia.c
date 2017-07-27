/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:02:42 by sbalcort          #+#    #+#             */
/*   Updated: 2017/07/26 17:23:38 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		start_julia(t_env *env, t_pic *image, t_nbr *nbr)
{
	nbr->cRe = -0.7;
	nbr->cIm = 0.25;
	nbr->transX = 0;
	nbr->transY = 0;
	nbr->zoom = 1;
	nbr->iterations = 500;
	t_pic *derp;
	derp = image;
	int i = -1;
	int	y = -1;
	int	x = -1;
	while (++y < WIN_Y)
	{
		nbr->newRe = (1.5 * ((x - WIN_X) / 2)) / ( 0.5 * nbr->zoom * WIN_X) + nbr->transX;
		nbr->newIm = ((y - WIN_Y) / 2) / (0.5 * nbr->zoom * WIN_Y) + nbr->transY;
		while (++x < WIN_X)
		{
			while (++i < nbr->iterations)
			{
				nbr->oldRe = nbr->newRe;
				nbr->oldIm = nbr->newIm;
				nbr->newRe = nbr->oldRe * nbr->oldRe - nbr->oldIm * nbr->oldIm + nbr->cRe;
				nbr->newIm = 2 * nbr->oldRe * nbr->oldRe * nbr->oldIm + nbr->cIm;
				if (((nbr->newRe * nbr->newRe) + (nbr->newIm * nbr->newIm)) > 4)
					break;
				nbr->color += 100;
			}
			if (i == nbr->iterations)
				nbr->color = 0;
			mlx_pixel_put(env->mlx, env->window, x, y, nbr->color);
			nbr->color = 500;
			i = -1;
		}
		x = 0;
	}

	
}


void		julia(void)
{
	t_env	*env;

	env = initialize_mlx("Julia");
	start_julia(env, env->image, env->image->nbr);
		
	//hooks(env);	
	mlx_loop(env->mlx);
}
