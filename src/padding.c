/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 07:32:57 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/22 14:23:19 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_norm.h"
#include "ft_stdlib.h"

void	pad_precision_str(char **str, int width)
{
	char	*ret;

	if (width < 0 || width >= (int)ft_strlen(*str))
		return ;
	if (!width)
	{
		if (!ft_set64((int64_t*)&ret, (int64_t)ft_calloc(1, sizeof(char))))
			return ;
	}
	else
		ret = ft_substr(*str, 0, width);
	ft_free(*str);
	*str = ret;
}

void	pad_width_str(char **str, t_fields *f)
{
	char	*ret;

	if (f->width < 0 || f->width < (int)ft_strlen(*str))
		return ;
	if (!ft_set64((int64_t*)&ret,
			(int64_t)ft_calloc(f->width + 1, sizeof(char))))
		return ;
	ft_memset(ret, ' ', f->width);
	if (f->flags & B1)
		ft_strncpy(ret, *str, ft_strlen(*str));
	else
		ft_strncpy(ret + f->width - ft_strlen(*str), *str, ft_strlen(*str));
	ft_free(*str);
	*str = ret;
}

void	pad_precision_num(char **str, int width)
{
	char	*ret;

	if (!width && **str == '0')
		if (!ft_set64((int64_t*)&ret, (int64_t)ft_calloc(1, sizeof(char))))
			return ;
	if (width || **str != '0')
	{
		if ((int)ft_strlen(*str) >= width || !ft_set64((int64_t*)&ret,
						(int64_t)ft_calloc(width + 1, sizeof(char))))
			return ;
		if (**str == '-')
		{
			ft_memset(ret + 1, '0', width - (ft_strlen(*str) - 1));
			ft_memcpy(ret + 1 + width - (ft_strlen(*str) - 1), *str + 1,
				ft_strlen(*str) - 1);
			ret[0] = '-';
		}
		if (**str != '-')
			ft_memset(ret, '0', width - ft_strlen(*str));
		if (**str != '-')
			ft_memcpy(ret + width - ft_strlen(*str), *str, ft_strlen(*str));
	}
	ft_free(*str);
	*str = ret;
}

/*
** Useless function required because of norminette complaining with a single
** line. Replace function call with the code inside.
*/

static void	stupid_func_bc_norm(char **str, char pad, char *ret, t_fields *f)
{
	if (**str == '-' && pad == '0')
		ft_memset(ret + 1, pad, f->width - (ft_strlen(*str) - 1));
	else
		ft_memset(ret, pad, f->width - ft_strlen(*str));
	if (**str == '-' && pad == '0')
		ft_memcpy(ret + 1 + f->width - ft_strlen(*str),
				 *str + 1, ft_strlen(*str) - 1);
	else
		ft_memcpy(ret + f->width - ft_strlen(*str), *str, ft_strlen(*str));
}

void	pad_width_num(char **str, t_fields *f)
{
	char	pad;
	char	*ret;

	if ((int)ft_strlen(*str) >= f->width || !ft_set64((int64_t*)&ret,
					(int64_t)ft_calloc(f->width + 1, sizeof(char))))
		return ;
	pad = ft_ternary8(f->precision == -1 && f->flags & B2, '0', ' ');
	if (f->flags & B1)
	{
		ft_memcpy(ret, *str, ft_strlen(*str));
		ft_memset(ret + ft_strlen(*str), ' ', f->width - ft_strlen(*str));
	}
	else
		stupid_func_bc_norm(str, pad, ret, f);
	if (**str == '-' && pad == '0')
		ret[0] = '-';
	ft_free(*str);
	*str = ret;
}
