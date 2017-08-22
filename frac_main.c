/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 20:00:22 by sbalcort          #+#    #+#             */
/*   Updated: 2017/08/22 10:37:22 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	new_frac(char *str)
{
	t_env *env;

	if (!ft_strcmp(str, "julia"))
		env = initialize_mlx("julia");
	if (!ft_strcmp(str, "mandelbrot"))
		env = initialize_mlx("mandelbrot");
	if (!(ft_strcmp(str, "ship")))
		env = initialize_mlx("ship");
	if (!(ft_strcmp(str, "attractor")))
		env = initialize_mlx("attractor");
	if (!(ft_strcmp(str, "mandel5")))
		env = initialize_mlx("mandel5");
	redraw(env);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 1)
		return (ft_err_usage(argc, argv));
	while (++i < argc)
	{
		if (ft_strncmp("mandel5", argv[i], 7) && ft_strncmp("julia", argv[i], 5) && ft_strncmp("mandelbrot", argv[i], 10) && ft_strncmp("ship", argv[i], 4) && ft_strncmp("attractor", argv[i], 9))
			ft_err_input(argv[i]);
		else

			new_frac(argv[i]);
	}
	return (0);
}
