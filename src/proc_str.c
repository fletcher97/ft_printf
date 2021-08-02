/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:52:12 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/22 17:12:51 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_norm.h"

int	proc_str(char *s, t_fields *f, char *str)
{
	int		ret;
	char	*temp;
	short	flag;

	flag = 0;
	if (!str && ft_set8((int8_t *)&temp, 1))
	{
		if (f->precision < 0 || f->precision > 5)
			str = ft_malloc(7);
		if (f->precision < 0 || f->precision > 5)
			ft_strcpy(str, "(null)");
		else
			str = ft_calloc(1, sizeof(char));
	}
	if (!flag)
		temp = ft_strdup(str);
	else
		temp = str;
	pad_precision_str(&temp, f->precision);
	pad_width_str(&temp, f);
	ft_putstr_fd(temp, STDOUT);
	ft_putstr_fd(s, STDOUT);
	ret = ft_strlen(temp) + ft_strlen(s);
	ft_free(temp);
	return (ret);
}

static int	stupid_func_bc_norm(char *temp, int ret, char *s)
{
	char	*aux;

	ft_set64((int64_t *)&aux, (int64_t)ft_substr(temp, 0, ft_strichr(temp, 1)));
	ft_putstr_fd(aux, STDOUT);
	ft_free(aux);
	ft_putchar_fd('\0', STDOUT);
	aux = ft_substr(temp, ft_strichr(temp, 1) + 1,
			ft_strlen(temp) - (ft_strichr(temp, 1) + 1));
	ft_putstr_fd(aux, STDOUT);
	ft_putstr_fd(s, STDOUT);
	ft_free(aux);
	ft_free(temp);
	return (ret);
}

int	proc_char(char *s, t_fields *f, char c)
{
	int		ret;
	char	*temp;

	temp = ft_calloc(2, sizeof(char));
	temp[0] = ft_ternary8(c, c, 1);
	pad_precision_num(&temp, f->precision);
	pad_width_num(&temp, f);
	ret = ft_strlen(temp) + ft_strlen(s);
	if (!c)
	{
		return (stupid_func_bc_norm(temp, ret, s));
	}
	ft_putstr_fd(temp, STDOUT);
	ft_putstr_fd(s, STDOUT);
	ft_free(temp);
	return (ret);
}
