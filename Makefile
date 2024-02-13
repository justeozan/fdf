# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 19:03:54 by ozasahin          #+#    #+#              #
#    Updated: 2024/02/13 19:47:13 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL: all

NAME	=	fdf

SRC		=	\
			src/fdf.c

# Controls
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJ		=	$(patsubst src/%.c, obj/%.o, $(SRC))

all:		force $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJ) -Llibft -Llibft

obj/%.o:	src/%.c include/fdf.h Makefile | obj
		$(CC) $(CFLAGS) -Iinclude -Ilibft -c $< -o $@

obj:
		mkdir -p obj

clean:
		$(RM) $(OBJ)
		make clean -C libft

fclean:		clean
		$(RM) $(NAME)
		make fclean -C libft

force:
		make -C libft

re:
		fclean all

.PHONY:	all clean fclean force re