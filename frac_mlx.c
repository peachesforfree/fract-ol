/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:15:58 by sbalcort          #+#    #+#             */
/*   Updated: 2017/07/26 00:18:10 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, WIN_X, WIN_Y, s);
	env->image = initialize_image(env);
	env->image->nbr = initialize_nbr();
	return (env);
}
