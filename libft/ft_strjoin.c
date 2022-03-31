/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:46:28 by naykim            #+#    #+#             */
/*   Updated: 2021/03/14 12:40:38 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	size_t			i;
	size_t			k;
	char			*str;

	i = 0;
	k = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	len1 = (unsigned int)ft_strlen(s1);
	len2 = (unsigned int)ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	while (k < len1)
		str[i++] = s1[k++];
	k = 0;
	while (k < len2)
		str[i++] = s2[k++];
	str[i] = '\0';
	return (str);
}
