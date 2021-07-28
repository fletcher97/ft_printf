/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:22:12 by mgueifao          #+#    #+#             */
/*   Updated: 2021/07/19 22:08:24 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conv.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_norm.h"
#include "ft_string.h"
#include "ft_printf.h"

int	proc_int(char *s, t_fields *f, int i)
{
	int		ret;
	char	*temp;
	char	*aux;

	temp = ft_itoa(i);
	pad_precision_num(&temp, f->precision);
	if (f->flags & B5 && i >= 0)
	{
		aux = ft_strjoin("+", temp);
		ft_free(temp);
		temp = aux;
	}
	pad_width_num(&temp, f);
	if (f->flags & B4 && !(f->flags & B5) && *temp != ' ' && i >= 0)
		ft_putchar_fd(' ', STDOUT);
	ft_putstr_fd(temp, STDOUT);
	ft_putstr_fd(s, STDOUT);
	ret = ft_strlen(temp) + ft_strlen(s);
	if (f->flags & B4 && !(f->flags & B5) && *temp != ' ' && i >= 0)
		ret++;
	ft_free(temp);
	return (ret);
}

int	proc_uint(char *s, t_fields *f, unsigned int i)
{
	int		ret;
	char	*temp;

	temp = ft_uitoa(i);
	pad_precision_num(&temp, f->precision);
	pad_width_num(&temp, f);
	if (f->flags & B4 && *temp != ' ')
		ft_putchar_fd(' ', STDOUT);
	ft_putstr_fd(temp, STDOUT);
	ft_putstr_fd(s, STDOUT);
	ret = ft_strlen(temp) + ft_strlen(s);
	if (f->flags & B4 && *temp != ' ')
		ret++;
	ft_free(temp);
	return (ret);
}

int	proc_uhex(char *s, t_fields *f, unsigned int i, short big)
{
	int		ret;
	char	*temp;
	char	*aux;

	if (big)
		aux = ft_uitoa_base(i, HEX_U);
	else
		aux = ft_uitoa_base(i, HEX_L);
	pad_precision_num(&aux, f->precision);
	if (f->flags & B6 && i > 0)
		temp = ft_strjoin((char *)ft_ternary64(big,
					(int64_t)"0X", (int64_t)"0x"), aux);
	else
		temp = ft_strdup(aux);
	ft_free(aux);
	pad_width_num(&temp, f);
	if (f->flags & B4 && *temp != ' ')
		ft_putchar_fd(' ', STDOUT);
	ft_putstr_fd(temp, STDOUT);
	ft_putstr_fd(s, STDOUT);
	ret = ft_strlen(temp) + ft_strlen(s);
	if (f->flags & B4 && *temp != ' ')
		ret++;
	ft_free(temp);
	return (ret);
}

int	proc_ptr(char *s, t_fields *f, void *ptr)
{
	int		ret;
	char	*temp;
	char	*aux;

	temp = ft_ultoa_base((unsigned long)ptr, HEX_L);
	aux = ft_strjoin("0x", temp);
	ft_free(temp);
	temp = aux;
	pad_precision_num(&temp, f->precision);
	pad_width_num(&temp, f);
	ft_putstr_fd(temp, STDOUT);
	ft_putstr_fd(s, STDOUT);
	ret = ft_strlen(temp) + ft_strlen(s);
	ft_free(temp);
	return (ret);
}

int	proc_uoct(char *s, t_fields *f, unsigned int i)
{
	int		ret;
	char	*temp;

	temp = ft_uitoa_base(i, OCT);
	pad_precision_num(&temp, f->precision);
	pad_width_num(&temp, f);
	if (f->flags & B4 && *temp != ' ')
		ft_putchar_fd(' ', STDOUT);
	ft_putstr_fd(temp, STDOUT);
	ft_putstr_fd(s, STDOUT);
	ret = ft_strlen(temp) + ft_strlen(s);
	if (f->flags & B4 && *temp != ' ')
		ret++;
	ft_free(temp);
	return (ret);
}
