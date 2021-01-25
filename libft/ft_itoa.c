/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:20:26 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/08 12:30:32 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	abs_s(int x)
{
	return (x < 0 ? x * -1 : x);
}

static char	*itoa_rec_s(int n, int i, int *s, int sign)
{
	char *ret;

	if (n == 0)
	{
		if ((ret = malloc(i + 1)) == NULL)
			return (NULL);
		*s = i - sign;
		ret[i] = '\0';
		return (ret);
	}
	if ((ret = itoa_rec_s(n / 10, i + 1, s, sign)) == NULL)
		return (NULL);
	ret[(*s) - i] = abs_s(n % 10) + '0';
	return (ret);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		s;

	if (n == 0)
	{
		if ((ret = malloc(2)) == NULL)
			return (NULL);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	if (n < 0)
	{
		if ((ret = itoa_rec_s(n, 1, &s, 0)) == NULL)
			return (NULL);
		ret[0] = '-';
	}
	else
		ret = itoa_rec_s(n, 0, &s, 1);
	return (ret);
}
