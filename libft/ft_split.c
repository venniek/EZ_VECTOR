/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:06:09 by naykim            #+#    #+#             */
/*   Updated: 2021/03/14 12:39:17 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_word(char const *s, char c)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

static int	len_word(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	*ft_free(char **split, int word)
{
	int		i;

	i = 0;
	while (i < word)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**make_split(char const *s, int w, char c, char **split)
{
	int		i;
	int		k;
	int		len;

	i = 0;
	while (i < w)
	{
		while (*s == c)
			s++;
		len = len_word(s, c);
		split[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!split[i])
			return (ft_free(split, i));
		k = 0;
		while (k < len)
			split[i][k++] = *s++;
		split[i][k] = '\0';
		i++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		w;

	if (!s)
		return (NULL);
	w = cnt_word(s, c);
	split = (char **)malloc(sizeof(char *) * (w + 1));
	if (!split)
		return (NULL);
	make_split(s, w, c, split);
	return (split);
}
