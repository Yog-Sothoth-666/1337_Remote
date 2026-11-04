/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:45:09 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/10/26 11:29:01 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*chr;

	i = 0;
	chr = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			chr = (char *)&s[i];
			return (chr);
		}
		i++;
	}
	if (s[i] == (char)c)
		chr = (char *)&s[i];
	return (chr);
}
