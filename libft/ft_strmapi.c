/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:20 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/08 09:32:50 by mgueifao         ###   ########.fr       */
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
	if (!ft_set64((int64_t *)&ret, (int64_t)malloc(size + 1)))
		return (NULL);
	ret[size] = '\0';
	while (--size)
		ret[size] = f(size, s[size]);
	ret[size] = f(size, s[size]);
	return (ret);
}
