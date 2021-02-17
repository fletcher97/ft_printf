/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_temp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:15:22 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/14 22:36:04 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEMP_H
# define FT_TEMP_H

# include <stddef.h>

void	ft_bzero(void *s, size_t n);
char	*ft_itoa_base(int n, const char *base);
char	*ft_itoa(int n);
char	*ft_uitoa(int n);

#endif
