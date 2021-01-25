/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:20 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/01 09:47:47 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if (!(ret = malloc(size + 1)))
		return (NULL);
	ret[size] = '\0';
	while (--size)
		ret[size] = f(size, s[size]);
	ret[size] = f(size, s[size]);
	return (ret);
}
