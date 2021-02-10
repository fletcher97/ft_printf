/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:42 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/08 08:34:10 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strwcnt_s(const char *str, const char *delim)
{
	int	i;
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	i = -1;
	while (str[++i])
	{
		if (!flag && !ft_strchr(delim, str[i]))
			flag = 1;
		else if (flag && ft_strchr(delim, str[i]))
		{
			flag = 0;
			count++;
		}
	}
	return (count + flag);
}

static char	*strtok_s(char *str, const char *delim)
{
	char		*ret;
	static char	*curr = NULL;

	if (((!curr || !*curr) && !str) || !delim)
		return (NULL);
	curr = (char*)ft_ternary64((int64_t)str, (int64_t)str, (int64_t)curr);
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
	curr = (char*)ft_ternary64((int64_t) * curr, (int64_t)curr, (int64_t) NULL);
	return ((char*)ft_ternary64((int64_t) * ret, (int64_t)ret, (int64_t) NULL));
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*dup;
	char	delim[2];
	int		cnt;
	int		pos;

	if (!s)
		return (NULL);
	delim[0] = c;
	delim[1] = '\0';
	cnt = strwcnt_s(s, delim) + 1;
	if (!ft_set64((int64_t *)&ret, (int64_t)malloc(sizeof(char *) * (cnt))))
		return (NULL);
	ret[--cnt] = NULL;
	if (!cnt)
		return (ret);
	dup = ft_strdup(s);
	pos = 0;
	ret[pos] = ft_strdup(strtok_s(dup, delim));
	while (++pos < cnt)
		ret[pos] = ft_strdup(strtok_s(NULL, delim));
	free(dup);
	return (ret);
}
