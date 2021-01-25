/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:48 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/03 05:22:41 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	islower_s(int c)
{
	return (c >= 'a' && c <= 'z');
}

int			ft_toupper(int c)
{
	if (islower_s(c))
		c -= 32;
	return (c);
}
