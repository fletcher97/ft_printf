CC := gcc
CFLAGS := -Wall -Werror -Wextra
SRCS := $(wildcard *.c)
OBJS := $(subst .c,.o,${SRCS})

all: libft.a

bonus: libft.a

libft.a: ${OBJS}
	ar rcs $@ $?

clean:
	rm -rf *.o

fclean: clean
	rm -rf libft.a

re: fclean all

.PHONY: all bonus fclean clean re
