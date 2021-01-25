/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 04:30:32 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/01 09:47:56 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	char		*ret;
	static char	*curr = NULL;

	if (((!curr || !*curr) && !str) || !delim)
		return (NULL);
	curr = str ? str : curr;
	while (*curr && ft_strchr(delim, *curr))
		curr++;
	ret = curr;
	while (*curr && !ft_strchr(delim, *curr))
		curr++;
	if (*curr)
	{
		*curr = '\0';
		curr++;
	}
	curr = *curr ? curr : NULL;
	return (*ret ? ret : NULL);
}
