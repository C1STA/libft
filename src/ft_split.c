/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:03:06 by wcista            #+#    #+#             */
/*   Updated: 2023/03/13 08:09:35 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	**ft_free_split(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		s[i] = NULL;
		i--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char	**ft_fill_split(char const *s, char c, char **split)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			len = ft_wordlen(s, c);
			split[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (!split[i])
				return (ft_free_split(split, i));
			j = 0;
			while (j < len)
				split[i][j++] = *s++;
			split[i][j] = '\0';
			i++;
		}
		else
			s++;
	}
	split[i] = '\0';
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	words = ft_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	if (!ft_fill_split(s, c, split))
		return (NULL);
	return (split);
}
