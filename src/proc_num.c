/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:22:12 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/11 10:34:59 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*proc_int(char *s, t_fields *f, int i)
{
	char *ret;
	char *temp;

	if (!f)
		return (malloc(0));
	temp = ft_itoa(i);
	pad_precision_num(&temp, f->precision);
	pad_width_num(&temp, f);
	ret = ft_strjoin(temp, s);
	free(temp);
	return (ret);
}

char	*proc_uint(char *s, t_fields *f, unsigned int i)
{
	char *ret;
	char *temp;

	if (!f)
		return (malloc(0));
	temp = ft_uitoa(i);
	pad_precision_num(&temp, f->precision);
	pad_width_num(&temp, f);
	ret = ft_strjoin(temp, s);
	free(temp);
	return (ret);
}

char	*proc_uhex(char *s, t_fields *f, unsigned int i, short big)
{
	char *ret;
	char *temp;

	if (!f)
		return (malloc(0));
	if (big)
		temp = ft_itoa_base(i, HEX_U);
	else
		temp = ft_itoa_base(i, HEX_L);
	pad_precision_num(&temp, f->precision);
	pad_width_num(&temp, f);
	ret = ft_strjoin(temp, s);
	free(temp);
	return (ret);
	return (s);
}

char	*proc_ptr(char *s, t_fields *f, void *ptr)
{
	if (!f || !s || !ptr)
		return (s);
	return (s);
}
