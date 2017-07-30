/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:02:42 by sbalcort          #+#    #+#             */
/*   Updated: 2017/07/29 20:48:16 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		start_julia(t_env *env, t_pic *image, t_nbr *nbr)
{
	/*nbr->cRe = .4;
	nbr->cIm = .4;
	nbr->transX = 0;
	nbr->transY = 0;
	nbr->zoom = 2;
	nbr->iterations = 50;*/
	t_pic *derp;
	derp = image;
	int i = 0;
	float	y = -1;
	float	x = -1;
	while (++y <= WIN_Y)
	{
		while (++x <= WIN_X)
		{
			nbr->newRe = (1.5 * (x - WIN_X / 2)) / (0.5 * nbr->zoom * WIN_X) + nbr->transX;
			nbr->newIm = (y - WIN_Y / 2) / (0.5 * nbr->zoom * WIN_Y) + nbr->transY;			
			/*if (x < (WIN_X / 2))
				nbr->newRe = 1.5 * (((WIN_X / 2) - x) / (WIN_X / 2));
			if (x >= (WIN_X / 2))
				nbr->newRe = 1.5 * ((x - (WIN_X / 2)) / (WIN_X / 2));
			if (y < (WIN_Y / 2))
				nbr->newIm = 1.5 * (((WIN_Y / 2) - y) / (WIN_Y / 2));
			if (y >= (WIN_Y / 2))
				nbr->newIm = 1.5 * ((y - (WIN_Y / 2)) / (WIN_Y / 2));
*/
			//printf("(%f,%f)[%f,%f] \n ", x, y, nbr->newRe, nbr->newIm);
			while (++i < nbr->iterations)
			{
				nbr->oldRe = nbr->newRe;
				nbr->oldIm = nbr->newIm;
				nbr->newRe =  ((nbr->oldRe * nbr->oldRe) - (nbr->oldIm * nbr->oldIm)) + nbr->cRe;
				nbr->newIm = (2 * nbr->oldRe * nbr->oldIm) + nbr->cIm;
				if (((nbr->newRe * nbr->newRe) + (nbr->newIm * nbr->newIm)) > 4)
					break;
				//printf("%d, ", i);
			}
			nbr->color = 16777215 + (i * 37); 
			if (i == nbr->iterations)
				nbr->color = 0;
			mlx_pixel_put(env->mlx, env->window, x, y, nbr->color);
			nbr->color = 500;
			i = -1;
		}
		x = 0;
	}

	
}


void		julia(t_env *env)
{
	//t_env	*env;

	//env = initialize_mlx("julia");
	redraw(env);
	hooks(env);
	//mlx_loop(env->mlx);
}
