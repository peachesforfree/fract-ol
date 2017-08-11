#include <fractol.h>



void	new_frac(char *str)
{
	t_env *env;

	if (!ft_strcmp(str, "julia"))
	{
		env = initialize_mlx("julia");
		julia(env);
	}
	else if (!ft_strcmp(str, "mandelbrot"))
	{
		env = initialize_mlx("mandelbrot");
		mandelbrot(env);
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 1)
		return (ft_err_usage(argc, argv));
	while (++i < argc)
	{
		if (ft_strcmp("julia", argv[i]) || ft_strcmp("mandelbrot", argv[i]))
			new_frac(argv[i]);
		else
			ft_err_input(argv[i]);
	}
	return (0);
}
