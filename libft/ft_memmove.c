/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:12:13 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/11/02 15:15:52 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (dest == src)
		return (dest);
	if (d < s)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
	return (dest);
}
