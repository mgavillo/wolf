# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 17:07:49 by mgavillo          #+#    #+#              #
#    Updated: 2019/07/20 12:54:10 by mgavillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_NAME = wolf.c			\
		   draw.c			\
		   map.c			\
		   bresenham.c		\
		   keyboard.c		\
		   raycasting.c		\
		   win.c			\
		   parse.c			\
		   create_text.c	\
		   event.c			\
		   minimap.c		\
		   apply_text.c		\
		   ray_calc.c		\
		   menu.c

SRC = $(addprefix $(SRCDIR),$(SRC_NAME))

OBJ_NAME = $(subst .c,.o,$(SRC_NAME))
OBJ = $(addprefix $(OBJDIR),$(OBJ_NAME))

HEADERS =-I includes
HEADER = ./includes/wolf.h

CC = gcc

CFLAGS =-Wall -Wextra -Werror -g

SDLLIB =-L lib
SDL =-l SDL2-2.0.0

LIBFT =./libft
FT_LIB =./libft/libft.a

OBJDIR =./objs/
SRCDIR =./srcs/
INCDIR =./includes/

all : $(FT_LIB) $(NAME)

$(OBJDIR)%.o : $(SRCDIR)%.c $(HEADER)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(MLX) -o $@ -c $<

$(FT_LIB):
	make -j4 -C $(LIBFT)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(HEADERS) $(SDL) -o $(NAME) $(FT_LIB) $(SDLLIB)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
