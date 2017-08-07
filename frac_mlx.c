/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:15:58 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/02 11:58:24 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			redraw(t_env *env)
{
	if (!ft_strcmp(env->name, "julia"))
		start_julia(env, env->image, env->image->nbr);
	//if (env->name == "mandelbrot")
	return (0);
}

void		put_directions(t_env *env)
{
	mlx_string_put(env->mlx, env->window, 20, 20, 0xFFFFFF,"Zoom: scroll up or down");
	mlx_string_put(env->mlx, env->window, 20, 40, 0XFFFFFF,"Shift: Use arrow keys");
	mlx_string_put(env->mlx, env->window, 20, 60, 0xFFFFFF,"Space Bar: reset to zero");
	mlx_string_put(env->mlx, env->window, 20, 80, 0xFFFFFF,"Change colors: Click");
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
	//ptr->bits_per_pixel = BIT_PER_PX;
	ptr->endian = ENDN;
	ptr->win_w = WIN_X;
	ptr->data = (int*)mlx_get_data_addr(ptr->img_ptr, &ptr->bits_per_pixel, &ptr->win_w, &ptr->endian);
	return (ptr);
}

void		setting_points(t_nbr *nbr)
{
	nbr->cRe = .25;
	nbr->cIm = .25;
	nbr->transX = 0;
	nbr->transY = 0;
	nbr->zoom = .75;
	nbr->iterations = 25;
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
