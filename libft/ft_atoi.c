/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:32:40 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/07 19:48:51 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace_s(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
c == '\r' || c == ' ');
}

int	ft_atoi(char *str)
{
	int	pos;
	int	sign;
	int	ret;

	sign = 1;
	ret = 0;
	pos = 0;
	while (isspace_s(str[pos]))
		pos++;
	if (str[pos] == '-' || str[pos] == '+')
		if (str[pos++] == '-')
			sign *= -1;
	while (str[pos] >= '0' && str[pos] <= '9')
		ret = (ret * 10) + (str[pos++] - '0') * sign;
	return (ret);
}
