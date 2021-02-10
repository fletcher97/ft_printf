/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:46:42 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/08 09:31:32 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size1;
	size_t	size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!ft_set64((int64_t *)&ret, (int64_t)malloc(size1 + size2 + 1)))
		return (NULL);
	ft_memcpy(ret, s1, size1);
	ft_memcpy(ret + size1, s2, size2 + 1);
	return (ret);
}
