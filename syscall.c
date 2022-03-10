/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:24:12 by gyeon             #+#    #+#             */
/*   Updated: 2022/03/10 17:24:13 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 헤더 대체 필요.
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	*ft_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
	{
		write(2, "malloc error!\n", 14);
		exit(1);
	}
	return (result);
}
