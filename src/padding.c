/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 07:32:57 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/07 13:58:46 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"
#include "libft.h"

void	pad_precision_num(char **str, int width)
{
	char	*ret;

	if (!width && **str == '0')
	{
		if (!(ret = ft_calloc(1, sizeof(char))))
			return ;
	}
	else
	{
		if ((int)ft_strlen(*str) >= width)
			return ;
		if (!(ret = ft_calloc(width + 1, sizeof(char))))
			return ;
		if (**str == '-')
			ft_memset(ret + 1, '0', width - (ft_strlen(*str) - 1));
		else
			ft_memset(ret, '0', width - ft_strlen(*str));
		if (**str == '-')
			ft_memcpy(ret + 1 + width - (ft_strlen(*str) - 1), *str + 1,\
				ft_strlen(*str) - 1);
		if (**str == '-')
			ret[0] = '-';
		else
			ft_memcpy(ret + width - ft_strlen(*str), *str, ft_strlen(*str));
	}
	free(*str);
	*str = ret;
}

void	pad_width_num(char **str, t_fields *f)
{
	char	pad;
	char	*ret;

	if ((int)ft_strlen(*str) >= f->width ||\
		!(ret = ft_calloc(f->width + 1, sizeof(char))))
		return ;
	pad = ' ';
	if (f->precision == -1 && f->flags & B2)
		pad = '0';
	if (f->flags & B1)
		ft_memcpy(ret, *str, ft_strlen(*str));
	if (f->flags & B1)
		ft_memset(ret + ft_strlen(*str), ' ', f->width - ft_strlen(*str));
	else
	{
		if (**str == '-' && pad == '0')
			ft_memset(ret + 1, pad, f->width - (ft_strlen(*str) - 1));
		else
			ft_memset(ret, pad, f->width - ft_strlen(*str));
		if (**str == '-' && pad == '0')
			ft_memcpy(ret + 1 + f->width - ft_strlen(*str), *str + 1, ft_strlen(*str) - 1);
		else
			ft_memcpy(ret + f->width - ft_strlen(*str), *str, ft_strlen(*str));
	}
	if (**str == '-' && pad == '0')
		ret[0] = '-';
	free(*str);
	*str = ret;
}
