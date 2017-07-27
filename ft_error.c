/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:09:33 by sbalcort          #+#    #+#             */
/*   Updated: 2017/07/25 23:17:20 by sbalcort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_err_memory(char *str)
{
	ft_putstr("Failure to allcoate memory for: ");
	ft_putstr(str);
	ft_putendl(" Please try a smaller window size");
}

int		ft_err_usage(int argc, char **argv)
{
	int i;

	i = 0;
	ft_putstr("Usage : ");
	if (argc != 2)
		ft_putstr(argv[0]);
	else if (argv[1])
		ft_putstr(argv[1]);
	ft_putstr(" <filename> [ case_size z_size ]\n");
	return (0);
}

int		ft_err_input(char *str)
{
	ft_putstr("Sorry option unavailable: ");
	ft_putstr(str);
	ft_putstr(" ... skipping ...\n");
	return (0);
}
