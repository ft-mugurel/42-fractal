#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 04:45:20 by mugurel           #+#    #+#              #
#    Updated: 2023/02/06 04:45:22 by mugurel          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS =	./src/fractol.c		\
		./src/hooks.c			\
		./src/mlx_utils.c		\
		./src/mandelbrot.c		\
		./src/julia.c			\
		./src/burning_ship.c	\
		./src/arrows.c			\
		./src/zoom.c			\
		./src/colors.c			\
		./src/extra.c

SRCBS = ./srcb/fractol_bonus.c			\
		./srcb/hooks_bonus.c			\
		./srcb/mlx_utils_bonus.c		\
		./srcb/mandelbrot_bonus.c		\
		./srcb/julia_bonus.c			\
		./srcb/burning_ship_bonus.c	\
		./srcb/arrows_bonus.c			\
		./srcb/zoom_bonus.c			\
		./srcb/colors_bonus.c			\
		./srcb/extra_bonus.c

OBJS = ${SRCS:.c=.o}
BOBJS = $(BSRCS:.c=.o)
NAME = fractol
NAME_BONUS = fractol_bonus
CC = gcc
CFLAGS =  -Wall -Wextra -Werror
LFLAGS = -framework OpenGL -framework AppKit -L./lib/mlx_lib -lmlx -I./include/
MLX = ./lib/mlx_lib/libmlx.a
LIBFT = ./lib/libft/libft.a
RM = rm -rf

all: $(MLX) ${NAME}

$(NAME): $(SRCS) $(MLX) $(LIBFT)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(LIBFT) $(MLX) -o $(NAME)

bonus : $(SRCBS) $(MLX) $(LIBFT)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCBS) $(LIBFT) -o $(NAME_BONUS)

$(MLX) :
	@make -C ./lib/mlx_lib

$(LIBFT) :
	@make -C ./lib/libft

re: fclean all

clean:
	${RM} ${OBJS} ${BOBJS}
	@make clean -C ./lib/mlx_lib
	@make clean -C ./lib/libft

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./lib/mlx_lib
	@make fclean -C ./lib/libft



.PHONY: all bonus clean fclean re
