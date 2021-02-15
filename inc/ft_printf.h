/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:21:10 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/11 10:27:20 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//TODO remove
# include <stdio.h>

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

# define B1 0x01
# define B2 0x02
# define B3 0x04
# define B4 0x08
# define B5 0x10
# define B6 0x20
# define B7 0x40
# define B8 0x80

# define FLAGS "-0*"

# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"

typedef struct	s_fields
{
	char flags;
	int width;
	int precision;
}				t_fields;

/*
** STRING FORMAT:
** %[flags][minimum field with][precision][length modifier]<conversio specifier>
** FLAGS:
**  #0- +	'	I
** MINIMUM FIELD WITH:
**  non-zero starting number
** PRECISION:
**
** LENGTH MODIFIER:
** CONVERSION SPECIFIER:
*/
int		ft_printf(const char *str, ...);

char	*proc_flags(char *s, t_fields *f);
char	*proc_width(char *s, t_fields *f);
char	*proc_precision(char *s, t_fields *f);
char	*proc_length(char *s, t_fields *f);
char	*proc_conv(char *s, t_fields *f, va_list args);

char	*proc_char(char *s, t_fields *f, char c);
char	*proc_str(char *s, t_fields *f, char *str);
char	*proc_ptr(char *s, t_fields *f, void *ptr);
char	*proc_int(char *s, t_fields *f, int i);
char	*proc_uint(char *s, t_fields *f, unsigned int i);
char	*proc_uhex(char *s, t_fields *f, unsigned int i, short big);

void	pad_width_num(char **str, t_fields *f);
void	pad_precision_num(char **str, int width);

#endif
