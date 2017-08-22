/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 18:11:54 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/14 22:28:01 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_hook(t_env *env)
{
	(void) env;
	exit(0);
}

void	zero_out(t_env *env)
{
	env->image->nbr->zoom = 1;
	env->image->nbr->transY = 0;
	env->image->nbr->transX = 0;
}

int		key_hook(int keycode, t_env *env)
{
	double zoom;
	zoom = env->image->nbr->zoom;
	if (keycode == 125)
		env->image->nbr->transY += .02 + (.001 / zoom);
	if (keycode == 126)
		env->image->nbr->transY -= .02 + (.001 / zoom);
	if (keycode == 124)
		env->image->nbr->transX += .02 + (.001 / zoom);
	if (keycode == 123)
		env->image->nbr->transX -= .02 + (.001 / zoom);
	if (keycode == 49)
	{
		if (env->image->nbr->color_rot == 0)
			env->image->nbr->color_rot = 1;
		else
			env->image->nbr->color_rot = 0;
		zero_out(env);
	}
	if (keycode == 53)
		exit_hook(env);
	redraw(env);
	return (0);
}

int		motion_hook(int x, int y, t_env *env)
{
	float	xx;
	float	yy;

	xx = x;
	yy = y;
	if (xx < (WIN_X / 2))
		env->image->nbr->cRe = -(((WIN_X / 2) - xx) / (WIN_X / 2));
	if (xx >= (WIN_X / 2))
		env->image->nbr->cRe = ((xx - (WIN_X / 2)) / (WIN_X / 2));
	if (yy < (WIN_Y / 2))
		env->image->nbr->cIm = -((WIN_Y / 2) - yy) / (WIN_Y / 2);
	if (yy >= (WIN_Y / 2))
		env->image->nbr->cIm = ((yy - (WIN_X / 2)) / (WIN_X / 2));
	redraw(env);
	return (0);
}

void	recenter(int x, int y, t_env *env)
{
	t_nbr *nbr;
	nbr = env->image->nbr;

	if (x >= (WIN_X / 2))
		nbr->transX -= ((((WIN_X / 2) - (float)x) / (WIN_X / 2)) / fabs(nbr->zoom) / 10);
	if (x < (WIN_X / 2))
		nbr->transX += ((((float)x - (WIN_X / 2)) / (WIN_X / 2)) / fabs(nbr->zoom) / 10);
	if (y >= (WIN_Y / 2))	
		nbr->transY += ((((float)y - (WIN_X / 2)) / (WIN_Y / 2)) / fabs(nbr->zoom) / 10);
	if (y < (WIN_Y / 2))
		nbr->transY -= ((((WIN_Y / 2) - (float)y) / (WIN_Y / 2)) / fabs(nbr->zoom) / 10);
}

int		mouse_hooks(int button, int x, int y, t_env *env)
{
	if (button == 5)
	{
		//env->image->nbr->zoom += (.05 * env->image->nbr->zoom);
		env->image->nbr->zoom *= 1.02;
		recenter(x, y, env);
	}	
	if (button == 4)
	{
		//env->image->nbr->zoom -= (.05 * env->image->nbr->zoom);
		env->image->nbr->zoom *= .98;
		recenter(x, y, env);
	}
	redraw(env);
	return (0);
}

void	hooks(t_env *env)
{
	//mlx_do_key_autorepeaton(env->mlx);
	//mlx_expose_hook(env->window, &redraw, env);
	mlx_hook(env->window, 6, 0, motion_hook, env);
	mlx_mouse_hook(env->window, &mouse_hooks, env);
	mlx_hook(env->window, 2, 0, &key_hook, env);
	mlx_hook(env->window, 17, 0, exit_hook, env);
	mlx_loop(env->mlx);
}
