/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:44 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/08 09:42:56 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isupper_s(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_tolower(int c)
{
	if (isupper_s(c))
		c += 32;
	return (c);
}
