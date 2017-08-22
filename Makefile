# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/21 15:02:02 by sbalcort          #+#    #+#              #
#    Updated: 2017/08/16 18:30:59 by sbalcort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -g -Wall -Werror -Wextra

LIBS = libs/minilibx/libmlx.a\
	   libs/libft/libft.a

SRCS = frac_main.c\
	   ft_error.c\
	   frac_julia.c\
	   frac_hooks.c\
	   frac_mandelbrot.c\
	   frac_mlx.c\
	   frac_ship.c\
	   frac_attractor.c\
	   frac_mandel5.c

OBJS = $(SRCS:.c=.o)

INC = includes/

FRAMEWORKS = -framework OpenGL -framework AppKit

all: $(NAME)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I$(INC) $(LIBS) $(FRAMEWORKS)

$(NAME):
	make -C libs/libft
	make -C libs/minilibx

clean:
	/bin/rm -f rm $(OFILES)
	make -C libs/libft/ clean
	make -C libs/minilibx/ clean

fclean: clean
	/bin/rm -f rm $(NAME)
	make -C libs/libft/ fclean
	make -C libs/minilibx/ clean

re:fclean all
