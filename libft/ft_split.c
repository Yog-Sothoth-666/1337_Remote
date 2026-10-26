/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:10:55 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/10/19 11:29:42 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && !is_word)
		{
			count++;
			is_word = 1;
		}
		else if (*s == c && is_word)
			is_word = 0;
		s++;
	}
	return (count);
}

static char	*craft_word(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static char	**ft_freee(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	char	**strs;

	count = word_count(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	strs[count] = NULL;
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		strs[i] = craft_word(s, c);
		if (!strs[i])
			return (ft_freee(strs, i));
		i++;
		while (*s != c && *s)
			s++;
	}
	return (strs);
}
