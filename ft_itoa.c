/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:40:28 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/11/02 09:40:14 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	digitnum(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
	if (n == 0)
		return (1);
	else if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static char	*createnum(long n, long len)
{
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		while (n != 0)
		{
			str[len--] = '0' + (n % 10);
			n /= 10;
		}
		if (len == 0)
			str[0] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	long	len;

	len = digitnum(n);
	nb = n;
	if (nb < 0)
		nb *= -1;
	return (createnum(nb, len));
}
