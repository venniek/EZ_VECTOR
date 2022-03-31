/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 04:16:26 by naykim            #+#    #+#             */
/*   Updated: 2021/03/14 14:23:57 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int a)
{
	int		i;
	int		len;
	char	*s;

	s = (char *)str;
	i = 0;
	len = ft_strlen(s);
	if (a == '\0')
		return (&s[len]);
	while (i < len)
	{
		if (s[len - i - 1] == a)
			return (&s[len - i - 1]);
		i++;
	}
	return (0);
}
