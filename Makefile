NAME = FDF

MLX_FLAGS = -L minilibx-linux -lmlx_Linux -lmlx -lXext -lX11

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS =  srcs/main.c \
		srcs/error.c \
		srcs/init_matrix.c \
		srcs/matrix_utils.c \
		srcs/draw_map.c \
		srcs/key_manager.c \
		srcs/window_manager.c \
		srcs/draw_utils.c \

OBJS    = ${SRCS:.c=.o}

LIBFT   = make all -C libft/

all : $(NAME)

%.o: %.c  include/fdf.h libft/libft.h
	@${CC} ${CFLAGS} -g3 -Iinclude -Ilibft/ -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -g3 -Iinclude -Ilibft/  -o $@ $^ $(MLX_FLAGS) libft/libft.a -lm


fclean : clean
		$(RM) $(NAME)
		@make -s fclean -C libft/

clean :
		$(RM) $(OBJS)

re : fclean all

libft:
		@make -s all -C libft/

.PHONY: all clean fclean re libft

