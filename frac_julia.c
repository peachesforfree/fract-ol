/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:02:42 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/02 12:09:14 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		start_julia(t_env *env, t_pic *image, t_nbr *nbr)
{
	t_env *derp;
	derp = env;
	int *buffer;
	
	buffer = image->data;
	int i = 0;
	int	y = -1;
	int	x = -1;
	
	while (++y <= WIN_Y)
	{
		while (++x <= WIN_X)
		{
			nbr->newRe = (x - WIN_X / 2) / (0.5 * nbr->zoom * WIN_X) + nbr->transX;
			nbr->newIm = (y - WIN_Y / 2) / (0.5 * nbr->zoom * WIN_Y) + nbr->transY;			
			while (++i < nbr->iterations)
			{
				nbr->oldRe = nbr->newRe;
				nbr->oldIm = nbr->newIm;
				nbr->newRe =  ((nbr->oldRe * nbr->oldRe) - (nbr->oldIm * nbr->oldIm)) + nbr->cRe;
				nbr->newIm = (2 * nbr->oldRe * nbr->oldIm) + nbr->cIm;
				if (((nbr->newRe * nbr->newRe) + (nbr->newIm * nbr->newIm)) > 4)
					break;
			}
			nbr->color = 16711680 + (i * 14080); 
			if (i == nbr->iterations)
				nbr->color = 0;
			buffer[((int)x + ((int)y * (int)WIN_X))] = (int)nbr->color;
			//image->data[((int)x + ((int)y * (int)WIN_X))] = (int)nbr->color;
			//mlx_pixel_put(env->mlx, env->window, x, y, nbr->color);
			nbr->color = 16711680;
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
	put_directions(env);
	mlx_put_image_to_window(env->mlx, env->window, env->image->img_ptr, 0, 0);
	hooks(env);
	//mlx_loop(env->mlx);
}
