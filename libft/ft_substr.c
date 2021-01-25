/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:39 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/01 09:48:04 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strcpy_s(char *dest, const char *src)
{
	char *d;

	d = dest;
	while (*src)
		*(d++) = *(src++);
	*d = *src;
	return (dest);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ret = malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	size = ft_strlen(s + start);
	size = size > len ? len : size;
	if (!(ret = malloc(size + 1)))
		return (NULL);
	ret = strcpy_s(ret, s + start);
	ret[size] = '\0';
	return (ret);
}
