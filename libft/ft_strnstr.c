/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 03:28:52 by naykim            #+#    #+#             */
/*   Updated: 2021/03/14 14:24:44 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *fin, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (fin[0] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		k = 0;
		if (str[i] == fin[k])
		{
			while (i + k < len && str[i + k] == fin[k])
			{
				k++;
				if (!fin[k])
					return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (0);
}
