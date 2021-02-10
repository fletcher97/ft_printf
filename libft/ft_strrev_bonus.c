/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:03:18 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/07 21:21:33 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	char	*temp;

	if (!str)
		return (NULL);
	temp = str;
	i = ft_strlen(temp) - 1;
	while (i > 0)
	{
		ft_swap(temp, temp + i, 1);
		temp++;
		i -= 2;
	}
	return (str);
}
