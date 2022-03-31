/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 03:43:18 by naykim            #+#    #+#             */
/*   Updated: 2021/03/14 12:36:22 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)ptr;
	while (n-- > 0)
		if (*(str++) == (unsigned char)value)
			return ((void *)--str);
	return (NULL);
}
