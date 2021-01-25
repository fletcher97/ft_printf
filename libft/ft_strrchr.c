/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:32 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/01 09:47:54 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *r;

	r = (s + ft_strlen(s));
	while (r > s && (t_uc)*r != (t_uc)c)
		r--;
	return ((char *)((t_uc)*r == (t_uc)c ? r : NULL));
}
