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

SRCBS =
OBJS = ${SRCS:.c=.o}
BOBJS = $(BSRCS:.c=.o)
NAME = fractol
CC = gcc
CFLAGS =  -Wall -Wextra -Werror
LFLAGS = -framework OpenGL -framework AppKit -L./lib/mlx_lib -lmlx -I./include/
MLX = ./lib/mlx_lib/libmlx.a
FT_PRINTF = ./lib/ft_printf/libftprintf.a
RM = rm -rf

all: $(MLX) ${NAME}

$(NAME): $(SRCS) $(MLX) $(FT_PRINTF)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(FT_PRINTF) $(MLX) -o $(NAME)

bonus : $(SRCBS) $(MLX) $(FT_PRINTF)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCBS) $(FT_PRINTF) -o $(NAME)

$(MLX) :
	@make -C ./lib/mlx_lib

$(FT_PRINTF) :
	@make -C ./lib/ft_printf

re: fclean all

clean:
	${RM} ${OBJS} ${BOBJS}
	@make clean -C ./lib/mlx_lib
	@make clean -C ./lib/ft_printf

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./lib/mlx_lib
	@make fclean -C ./lib/ft_printf



.PHONY: all bonus clean fclean re .c.o
