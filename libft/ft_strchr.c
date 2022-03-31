/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 02:54:47 by naykim            #+#    #+#             */
/*   Updated: 2021/03/14 12:39:33 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int a)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < ft_strlen(str) + 1)
	{
		if (s[i] == a)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
