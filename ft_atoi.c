/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 19:07:26 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/11/05 11:12:14 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_guard(int s)
{
	if (s > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	n;
	int		s;

	i = 0;
	s = 1;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		if (n > (LONG_MAX - (nptr[i] - '0')) / 10)
			return (ft_guard(s));
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	return ((n * s));
}
