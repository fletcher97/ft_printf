/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:43:24 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/17 15:33:14 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>

#include "ft_string.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_printf.h"

/*
** Same as strtok but doesn't change the original string and return a duplicate
** of the token that need to be freed.
*/
static char	*ft_strtok_m(char *str)
{
	char		*ret;
	static char	*curr = NULL;

	if (((!curr || !*curr) && !str))
		return (NULL);
	curr = str ? str : curr;
	ret = curr;
	curr++;
	if (*ret == '%' && *curr == '%')
	{
		ret++;
		curr++;
	}
	else if(*ret == '%')
		ret++;
	while (*curr && *curr != '%')
		curr++;
	ret = ft_substr(ret, 0, curr - ret);
	curr = *curr ? curr : NULL;
	return (*ret ? ret : NULL);
}

// va_arg(list, int);
static int	proc(char *s, va_list args)
{
	t_fields	*fields;
	int			ret;

	if (!args || !(fields = ft_malloc(sizeof(t_fields))))
		return (-1);
	s = proc_flags(s, fields);
	if (fields->flags != -1)
	{
		s = proc_width(s, fields);
		s = proc_precision(s, fields);
		s = proc_length(s, fields);
		s = proc_conv(s, fields, args);
		ft_putstr_fd(s, 1);
	}
	ret = ft_strlen(s);
	ft_free(s);
	ft_free(fields);
	return (ret);
}

int			ft_printf(const char *str, ...)
{
	char *s;
	char *tok;
	int ret;
	va_list args;

	if (!str)
		return (0);
	s = ft_strdup(str);
	ret = 0;
	tok = ft_strtok_m(s);
	va_start(args, str);
	while(tok)
	{
		if (*tok == '%' || (!ret && *str != '%'))
		{
			ret += ft_strlen(tok);
			ft_putstr_fd(tok, 1);
		}
		else
		{
			ret += proc(tok, args);
		}
		ft_free(tok);
		tok = ft_strtok_m(NULL);
	}
	va_end(args);
	ft_free(s);
	return (ret);
}
