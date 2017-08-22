/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:15:58 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/22 10:43:16 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			redraw(t_env *env)
{
	if (!ft_strcmp(env->name, "julia"))
		julia(env);
	if (!ft_strcmp(env->name, "mandelbrot"))
		mandelbrot(env);
	if (!ft_strcmp(env->name, "ship"))
		ship(env);
	if (!ft_strcmp(env->name, "attractor"))
		attractor(env);
	if (!ft_strcmp(env->name, "mandel5"))
		mandel5(env);
	return (0);
}

void		put_directions(t_env *env)
{
	mlx_string_put(env->mlx, env->window, 20, 20, 0xFFFFFF,"Zoom: scroll up or down");
	mlx_string_put(env->mlx, env->window, 20, 40, 0XFFFFFF,"Shift: Use arrow keys");
	mlx_string_put(env->mlx, env->window, 20, 60, 0xFFFFFF,"Space Bar: reset to zero and rotate color");
	mlx_string_put(env->mlx, env->window, 20, 80, 0xFFFFFF,"Warning : potential seizures");
}

void		*initialize_nbr(void)
{
	t_nbr *nbr;

	nbr = (t_nbr*)malloc(sizeof(t_nbr));
	return (nbr);
}

void		*initialize_image(t_env *env)
{
	t_pic	*ptr;

	ptr = (t_pic*)malloc(sizeof(t_pic));
	ptr->img_ptr = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	ptr->data = (int*)mlx_get_data_addr(ptr->img_ptr, &ptr->bits_per_pixel, &ptr->win_w, &ptr->endian);
	return (ptr);
}

void		setting_points(t_nbr *nbr)
{
	nbr->cRe = .1;
	nbr->cIm = -.1;
	nbr->transX = 0;
	nbr->transY = 0;
	nbr->zoom = 1;
	nbr->max_iterations = 20;
	nbr->color_rot = 0;
}

void		*initialize_mlx(char *str)
{
	t_env	*env;
	char	*s;

	s = ft_strjoin("Fract'ol: ", str);
	s = ft_strnjoin(s, "\tDimensions: ", 1);
	s = ft_strnjoin(s, ft_itoa(WIN_X), 1);
	s = ft_strnjoin(s," x ", 1);
	s = ft_strnjoin(s, ft_itoa(WIN_Y), 1);
	env = (t_env*)malloc(sizeof(t_env));
	env->name = ft_strdup(str);
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, WIN_X, WIN_Y, s);
	env->image = initialize_image(env);
	env->image->nbr = initialize_nbr();
	setting_points(env->image->nbr);
	return (env);
}
