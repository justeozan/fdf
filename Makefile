# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 19:03:54 by ozasahin          #+#    #+#              #
#    Updated: 2024/03/27 14:02:48 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL: all

NAME	=	fdf

SRC		=	\
			src/apply_rotation.c\
			src/utils/color_utils.c\
			src/create_frame.c\
			src/displays.c\
			src/draw_line.c\
			src/free_fdf.c\
			src/get_map.c\
			src/init_fdf.c\
			src/key_manager.c\
			src/main.c\
			src/utils/map_utils.c\
			src/utils/proj_utils.c

OBJDIR		=	obj
OBJ			=	$(patsubst src/%.c, obj/%.o, $(SRC))

# Controls
CC			=	gcc -g
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-Iinclude -Ilibft -Imlx_linux
LINKS		=	-Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
RM			=	rm -f

# Colors
COLOR_RESET			=	\033[0m
COLOR_RED			=	\033[0;31m
COLOR_GREEN			=	\033[0;32m
COLOR_PURPLE		=	\033[0;95m
COLOR_BLUE			=	\033[0;34m

# Colored Messages
MESSAGE_COMPILE		=	$(COLOR_BLUE)Compiling the program...$(COLOR_RESET)
MESSAGE_DONE		=	$(COLOR_GREEN)Compilation completed.$(COLOR_RESET)
MESSAGE_CLEAN		=	$(COLOR_PURPLE)Cleaning up...$(COLOR_RESET)
MESSAGE_CLEAN_DONE	=	$(COLOR_PURPLE)Cleanup completed.$(COLOR_RESET)

all:		force $(NAME)

$(NAME):	$(OBJ) libft/libft.a
		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LINKS) -o $(NAME)
		@echo "$(MESSAGE_DONE)"

obj/%.o:	src/%.c include/fdf.h libft/libft.h mlx_linux/mlx.h Makefile | $(OBJDIR)
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
		@mkdir -p $(OBJDIR)
		@mkdir -p $(OBJDIR)/utils

clean:
		@$(RM) -r $(OBJDIR)
		@make clean -C libft -s
		@make clean -C mlx_linux -s
		@echo "$(MESSAGE_CLEAN_DONE)"

fclean:		clean
		@$(RM) $(NAME)
		@make fclean -C libft -s
		@make clean -C mlx_linux -s

force:
		@make -C libft -s
		@make -C mlx_linux -s

re:		fclean all

.PHONY:	all clean fclean force re