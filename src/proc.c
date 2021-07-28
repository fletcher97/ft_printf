/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:57:09 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/22 16:27:43 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_string.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_ctype.h"
#include "ft_printf.h"

char	*proc_flags(char *s, t_fields *f)
{
	int	i;

	f->flags = 0;
	i = ft_strichr(FLAGS, *s);
	while (*s && i != -1 && f->flags != -1)
	{
		if ((f->flags & (1 << i)) == 0)
			f->flags |= 1 << i;
		else
		{
			f->flags = -1;
		}
		s++;
		if (*s)
			i = ft_strichr(FLAGS, *s);
	}
	return (s);
}

char	*proc_width(char *s, t_fields *f, va_list args)
{
	f->width = -1;
	if ((*s == '*' && s++) || f->flags & B3)
	{
		f->width = (int)va_arg(args, int);
		if (f->width < 0)
			f->flags |= (1 << ft_strichr(FLAGS, '-'));
		if (f->width < 0)
			f->width = ft_abs(f->width);
	}
	else if (ft_isdigit(*s))
	{
		f->width = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
	}
	return (s);
}

char	*proc_precision(char *s, t_fields *f, va_list args)
{
	f->precision = -1;
	if (*s == '.' && s++)
	{
		if (*s == '*' && s++)
		{
			f->precision = (int)va_arg(args, int);
			if (f->precision < 0)
				f->precision = -1;
		}
		else
		{
			f->precision = ft_atoi(s);
			while (ft_isdigit(*s))
				s++;
		}
	}
	return (s);
}

char	*proc_length(char *s, t_fields *f)
{
	if (!f)
		return (s);
	return (s);
}

int	proc_conv(char *s, t_fields *f, va_list args)
{
	if (*s == '%')
		return (proc_char(++s, f, '%'));
	if (*s == 'c')
		return (proc_char(++s, f, (char)va_arg(args, int)));
	if (*s == 's')
		return (proc_str(++s, f, (char *)va_arg(args, char *)));
	if (*s == 'p')
		return (proc_ptr(++s, f, (void *)va_arg(args, void *)));
	if (*s == 'd' || *s == 'i')
		return (proc_int(++s, f, (int)va_arg(args, int)));
	if (*s == 'u')
		return (proc_uint(++s, f, (unsigned int)va_arg(args, unsigned int)));
	if (*s == 'x')
		return (proc_uhex(++s, f, (unsigned int)va_arg(args, unsigned int), 0));
	if (*s == 'X')
		return (proc_uhex(++s, f, (unsigned int)va_arg(args, unsigned int), 1));
	if (*s == 'o')
		return (proc_uoct(++s, f, (unsigned int)va_arg(args, unsigned int)));
	ft_putstr_fd(s, STDOUT);
	return (ft_strlen(s));
}
