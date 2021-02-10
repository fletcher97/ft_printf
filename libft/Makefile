CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

AR = ar rcs

NAME = libft.a

OBJS =	ft_atoi.o						\
		ft_bzero.o						\
		ft_calloc.o						\
		ft_isalnum.o					\
		ft_isalpha.o					\
		ft_isascii.o					\
		ft_isdigit.o					\
		ft_isprint.o					\
		ft_itoa.o						\
		ft_memccpy.o					\
		ft_memchr.o						\
		ft_memcmp.o						\
		ft_memcpy.o						\
		ft_memmove.o					\
		ft_memset.o						\
		ft_putchar_fd.o					\
		ft_putendl_fd.o					\
		ft_putnbr_fd.o					\
		ft_putstr_fd.o					\
		ft_split.o						\
		ft_strchr.o						\
		ft_strdup.o						\
		ft_strjoin.o					\
		ft_strlcat.o					\
		ft_strlcpy.o					\
		ft_strlen.o						\
		ft_strmapi.o					\
		ft_strncmp.o					\
		ft_strnstr.o					\
		ft_strrchr.o					\
		ft_strtrim.o					\
		ft_substr.o						\
		ft_tolower.o					\
		ft_toupper.o					\

OBJS_BONUS =	ft_lstadd_back.o		\
				ft_lstadd_front.o		\
				ft_lstclear.o			\
				ft_lstdelone.o			\
				ft_lstiter.o			\
				ft_lstlast.o			\
				ft_lstmap.o				\
				ft_lstnew.o				\
				ft_lstsize.o			\
				ft_abs_bonus.o			\
				ft_islower_bonus.o		\
				ft_isspace_bonus.o		\
				ft_isupper_bonus.o		\
				ft_strcpy_bonus.o		\
				ft_strjoin_m_bonus.o	\
				ft_strtok_bonus.o		\
				ft_strwcnt_bonus.o		\
				ft_strchr_i_bonus.o		\
				ft_max_bonus.o			\
				ft_min_bonus.o			\
				ft_uitoa_bonus.o		\
				ft_itoa_base_bonus.o	\
				ft_swap_bonus.o			\
				ft_strrev_bonus.o		\
				ft_ternary_bonus.o		\
				ft_set_bonus.o			\

default : ${NAME}

all : bonus

$(NAME) : ${OBJS}
	${AR} ${NAME} ${OBJS}

bonus : ${NAME} ${OBJS_BONUS}
	${AR} ${NAME} ${OBJS_BONUS}

%.o : %.c
	$(CC) ${CFLAGS} -g -c $< -o $@

.PHNONY : clean fclean re all

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean : clean
	rm -f ${NAME} ${NAME:.a=.so}

re : fclean all

so:
	$(CC) -fPIC $(CFLAGS) -c $(OBJS:.o=.c) $(OBJS_BONUS:.o=.c)
	gcc -shared -o libft.so $(OBJS) $(OBJS_BONUS)

test : all
	${CC} ${DFLAGS} tests/main.c -L. -l:libft.a -I . -o test
