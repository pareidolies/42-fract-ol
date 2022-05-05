SRCS		= main.c

SRCS_DIR	= ./srcs/

SRCS_PATH	= $(SRCS:%=$(SRCS_DIR)%)

OBJS		= $(SRCS_PATH:%.c=%.o)

PATH_LIBFT	= -C libft --no-print-directory

PATH_PRINTF	= -C printf --no-print-directory

PATH_MLX	= -C mlx_linux --no-print-directory

LIBRARY		= ./libft/libft.a

LIBRARY_B	= ./printf/libftprintf.a

NAME		= fractol

RM		= rm -f

CC		= cc -Wall -Wextra -Werror

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		$(NAME)

$(NAME): $(OBJS)
		$(MAKE) $(PATH_MLX)
		$(MAKE) $(PATH_LIBFT)
		$(MAKE) $(PATH_PRINTF)
		$(CC) $(SRCS_PATH) $(LIBRARY) $(LIBRARY_B) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME)

clean:
		$(MAKE) clean $(PATH_LIBFT)
		$(MAKE) clean $(PATH_PRINTF)
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
		$(MAKE) fclean $(PATH_LIBFT)
		$(MAKE) fclean $(PATH_PRINTF)
		${RM} ${NAME}

re:		fclean ${NAME}

.PHONY:		all clean fclean re
