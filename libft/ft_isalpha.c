/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:19:14 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/04 13:31:24 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isupper_s(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	islower_s(int c)
{
	return (c >= 'a' && c <= 'z');
}

int			ft_isalpha(int c)
{
	return (isupper_s(c) || islower_s(c));
}
