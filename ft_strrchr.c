/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:04:38 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/11/02 10:42:20 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*chr;

	i = ft_strlen(s);
	chr = NULL;
	while (i > 0)
	{
		if (s[i] == (char)c)
		{
			chr = (char *)&s[i];
			return (chr);
		}
		i--;
	}
	if (s[0] == (char)c)
		chr = (char *)&s[i];
	return (chr);
}
