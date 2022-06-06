SRCS		= main.c start.c parse.c draw.c compute.c maths.c transpose.c hook.c color.c utils.c

SRCS_DIR	= ./srcs/

SRCS_PATH	= $(SRCS:%=$(SRCS_DIR)%)

OBJS		= $(SRCS_PATH:%.c=%.o)

PATH_LIBFT	= -C libft --no-print-directory

PATH_MLX	= -C mlx_linux --no-print-directory

LIBRARY		= ./libft/libft.a ./mlx_linux/libmlx.a

NAME		= fractol

RM		= rm -f

CC		= cc -Wall -Wextra -Werror

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		$(NAME)

./libft/libft.a :
	make -C ./libft

./mlx_linux/libmlx.a :
	make -C ./mlx_linux

$(NAME): $(LIBRARY) $(OBJS)
		$(CC) $(OBJS) $(LIBRARY) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME)

clean:
		$(MAKE) clean $(PATH_LIBFT)
		$(MAKE) clean $(PATH_MLX)
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
		$(MAKE) fclean $(PATH_LIBFT)
		${RM} ${NAME}

re:		fclean ${NAME}

bonus:		$(NAME)

norm:		
		norminette ./libft ./srcs ./includes

.PHONY:		all clean fclean re
