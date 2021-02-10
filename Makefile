CC = gcc
BIN_DIR = bin
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror -g #TODO remove -g

AR = ar rcs

LIB = libft/libft.a
NAME = libftprintf.a

OBJS =	ft_printf.o	\
		proc.o		\
		proc_num.o	\
		proc_str.o	\
		padding.o	\

OBJS_BONUS =

vpath %.o $(OBJ_DIR)
vpath %.h $(INC_DIR)
vpath %.c $(SRC_DIR)

default : ${NAME}

all : bonus

${NAME} : ${OBJS} ${LIB}
	cp ${LIB} ${NAME}
	${AR} ${NAME} $(addprefix $(OBJ_DIR)/, $(OBJS))

bonus : ${NAME} ${OBJS_BONUS}
	${AR} ${NAME} ${OBJS_BONUS}

%.o : %.c
	$(CC) ${CFLAGS} -c $< -I $(INC_DIR) -o $(OBJ_DIR)/$@

clean :
	rm -f ${OBJ_DIR}/*

fclean : clean
	rm -f ${NAME}
	rm -f ${LIB}

re : fclean all

${LIB} :
	make all -C libft
	make clean -C libft

test : CFLAGS += -g -fsanitize=address
test : all
	${CC} ${CFLAGS} tests/main.c -L. -l:libftprintf.a -I inc -o test

.PHNONY : clean fclean re all debug
