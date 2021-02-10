/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:06:41 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/08 09:42:35 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *e1, void *e2, size_t size)
{
	void	*temp;

	temp = malloc(size);
	ft_memcpy(temp, e1, size);
	ft_memcpy(e1, e2, size);
	ft_memcpy(e2, temp, size);
	free(temp);
}
