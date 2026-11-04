/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:44:06 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/10/28 14:01:14 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
		sub = ft_strdup("\0");
	else
	{
		if (len > l - start)
			len = l - start;
		sub = ft_calloc(len + 1, sizeof(char));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, &s[start], len + 1);
	}
	return (sub);
}
