/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:15:58 by sbalcort          #+#    #+#             */
/*   Updated: 2017/07/29 21:15:16 by sbalcort         ###   ########.fr       */
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
	ptr->image = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	ptr->pixel_cnt = (size_t*)mlx_get_data_addr(ptr->image, &ptr->bits_per_pixel, &ptr->size_line, &ptr->endian);
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
