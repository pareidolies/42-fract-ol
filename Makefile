SRCS		=	main.c start.c parse.c draw.c compute.c maths.c transpose.c hook.c

SRCS_BONUS	=

OBJS		=	$(addprefix build/,${SRCS:.c=.o})

OBJS_BONUS	=	$(addprefix build/,${SRCS_BONUS:.c=.o})

NAME		=	fractol

CFLAGS		=	-Wall -Werror -Wextra

INCLUDE		=	includes/

LIBS		=	-lm -lXext -lX11

MY_LIBS		=	libs/libft/libft.a libs/minilibx-linux/libmlx.a

MAX_SPEED	=	100

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} -I ${INCLUDE} -D MAX_SPEED=$(MAX_SPEED) -c $< -o $@ -O3 -fPIE

libs/libft/libft.a	:
	make -C libs/libft

libs/minilibx-linux/libmlx.a	:
	make -C libs/minilibx-linux

$(NAME)	:	${MY_LIBS} ${OBJS}
	 gcc ${CFLAGS} ${OBJS} ${MY_LIBS} ${LIBS} -o ${NAME} -O3 -fPIE

clean	:
	rm -Rf build/
	make -C libs/libft clean
	make -C libs/minilibx-linux clean

fclean	:	clean
	rm -f ${NAME}
	make -C libs/libft fclean

re		:	fclean ${NAME}

bonus	:	${MY_LIBS} ${OBJS} $(OBJS_BONUS)
	gcc ${CFLAGS} ${LIBS} ${OBJS} ${OBJS_BONUS} -o ${NAME}

.PHONY	:	all clean fclean re bonus
