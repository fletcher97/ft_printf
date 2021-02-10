/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:20:35 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/08 09:47:13 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_ipair
{
	int	a;
	int	b;
}				t_ipair;

typedef unsigned char	t_uc;

/*
** Part I
*/

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(char *nptr);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);

/*
** Part II
*/

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Bonus
*/

t_list			*ft_lstnew(void *conten);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*
** Extra
*/

int				ft_abs(int x);
int				ft_islower(int c);
int				ft_isspace(char c);
int				ft_isupper(char c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strtok(char *str, const char *delim);
int				ft_strwcnt(const char *str, const char *delim);
char			*ft_strjoin_m(int size, char **strs, char *sep);
int				ft_strchr_i(const char *str, const char c);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
char			*ft_uitoa(int n);
char			*ft_itoa_base(int n, const char *base);
void			ft_swap(void *e1, void *e2, size_t size);
char			*ft_strrev(char *str);

/*
** Norm free
*/

int8_t			ft_ternary8(int flag, int8_t a, int8_t b);
int16_t			ft_ternary16(int flag, int16_t a, int16_t b);
int32_t			ft_ternary32(int flag, int32_t a, int32_t b);
int64_t			ft_ternary64(int flag, int64_t a, int64_t b);
int8_t			ft_set8(int8_t *a, int8_t b);
int16_t			ft_set16(int16_t *a, int16_t b);
int32_t			ft_set32(int32_t *a, int32_t b);
int64_t			ft_set64(int64_t *a, int64_t b);

#endif
