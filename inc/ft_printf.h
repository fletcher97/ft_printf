/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:21:10 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/22 14:30:32 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define B1 0x01
# define B2 0x02
# define B3 0x04
# define B4 0x08
# define B5 0x10
# define B6 0x20
# define B7 0x40
# define B8 0x80

# define FLAGS "-0* "
# define CONVS "%cdixXspu"

typedef struct s_fields
{
	char	flags;
	int		width;
	int		precision;
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
char	*proc_width(char *s, t_fields *f, va_list args);
char	*proc_precision(char *s, t_fields *f, va_list args);
char	*proc_length(char *s, t_fields *f);
int		proc_conv(char *s, t_fields *f, va_list args);

int		proc_char(char *s, t_fields *f, char c);
int		proc_str(char *s, t_fields *f, char *str);
int		proc_ptr(char *s, t_fields *f, void *ptr);
int		proc_int(char *s, t_fields *f, int i);
int		proc_uint(char *s, t_fields *f, unsigned int i);
int		proc_uhex(char *s, t_fields *f, unsigned int i, short big);
int		proc_uoct(char *s, t_fields *f, unsigned int i);

void	pad_precision_str(char **str, int width);
void	pad_width_str(char **str, t_fields *f);
void	pad_width_num(char **str, t_fields *f);
void	pad_precision_num(char **str, int width);

#endif
