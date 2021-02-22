/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:43:24 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/22 16:24:16 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_norm.h"
#include "ft_printf.h"

/*
** Same as strtok but doesn't change the original string and return a duplicate
** of the token that need to be freed.
*/

static char	*ft_strtok_m(char *str)
{
	static char	*curr = NULL;
	char		*ret;
	short		searching;

	if (!curr && !str)
		return (NULL);
	searching = 1;
	if (!curr)
		searching = 0;
	curr = (char *)ft_ternary64(!!str, (uint64_t)str, (uint64_t)curr);
	ret = curr;
	if (*curr == '%' && searching)
		ret++;
	if (*curr == '%' && searching)
		curr++;
	while (*curr && (*curr != '%' || searching))
	{
		if (ft_strchr(CONVS, *curr))
			searching = 0;
		curr++;
	}
	curr = (char *)ft_ternary64(!!*curr, (uint64_t)curr, 0);
	return (ft_substr(ret, 0, curr - ret));
}

static int	proc(char *s, va_list args)
{
	t_fields	*fields;
	int			ret;

	if (!args || !(ft_set64((int64_t*)&fields,
				(uint64_t)ft_malloc(sizeof(t_fields)))))
		return (-1);
	s = proc_flags(s, fields);
	if (fields->flags != -1)
	{
		s = proc_width(s, fields, args);
		s = proc_precision(s, fields, args);
		s = proc_length(s, fields);
		ret = proc_conv(s, fields, args);
	}
	ft_free(fields);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	char	*s;
	char	*tok;
	int		ret;
	va_list	args;

	if (!str)
		return (0);
	s = ft_strdup(str);
	ret = 0;
	tok = ft_strtok_m(s);
	va_start(args, str);
	while (tok)
	{
		if (*tok == '%' || (!ret && *str != '%'))
			ft_putstr_fd(tok, 1);
		if (*tok == '%' || (!ret && *str != '%'))
			ret += ft_strlen(tok);
		else
			ret += proc(tok, args);
		ft_free(tok);
		tok = ft_strtok_m(NULL);
	}
	va_end(args);
	ft_free(s);
	return (ret);
}
