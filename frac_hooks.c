/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 18:11:54 by sbalcort          #+#    #+#             */
/*   Updated: 2017/07/31 12:05:40 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_hook(t_env *env)
{
	(void) env;
	exit(0);
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
		env->image->nbr->cIm = ((WIN_Y / 2) - yy) / (WIN_Y / 2);
	if (yy >= (WIN_Y / 2))
		env->image->nbr->cIm = -((yy - (WIN_X / 2)) / (WIN_X / 2));
	redraw(env);
	return (0);
}

void	hooks(t_env *env)
{
	//mlx_do_key_autorepeaton(env->mlx);
	mlx_expose_hook(env->window, &redraw, env);
	mlx_hook(env->window, 6, 0, motion_hook, env);
	//mlx_mouse_hook(env->window, &mouse_hooks, env);
	//mlx_hook(env->window, 2, 0, &key_hook, env);
	mlx_hook(env->window, 17, 0, exit_hook, env);

	mlx_loop(env->mlx);
}
