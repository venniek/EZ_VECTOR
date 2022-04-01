/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:41:10 by ygj               #+#    #+#             */
/*   Updated: 2021/10/02 12:41:45 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_bufflst	*arr[OPEN_MAX] = {NULL};

	if (fd >= 0 && fd < OPEN_MAX && BUFFER_SIZE > 0 && line)
	{
		if (arr[fd] == NULL || (arr[fd] != NULL && arr[fd]->num_nl == 0))
			while (rnadd_lst(fd, &arr[fd])
				&& !(find_lastlst(arr[fd])->num_nl
					|| find_lastlst(arr[fd])->is_eof))
				;
		if (arr[fd] != NULL)
		{
			*line = get_line(&arr[fd]);
			if (*line != NULL)
			{
				if (arr[fd]->is_eof == TRUE)
				{
					free_lst(&arr[fd], FREE_ALL);
					return (0);
				}
				return (1);
			}
		}
	}
	return (-1);
}

void	cnt_nl(t_bufflst *lst)
{
	short	flg;
	size_t	index;

	flg = 0;
	index = 0;
	while (*(lst->buff + index) != '\0')
	{
		if (*(lst->buff + index++) == '\n')
			lst->num_nl++;
	}
}

t_bufflst	*rnadd_lst(int fd, t_bufflst **lst)
{
	t_bufflst	*last_lst;

	last_lst = add_lastlst(lst);
	if (last_lst != NULL)
	{
		last_lst->leng = read(fd, last_lst->buff, BUFFER_SIZE);
		if (last_lst->leng == ERR)
			free_lst(lst, FREE_ALL);
		else
		{
			*(last_lst->buff + last_lst->leng) = '\0';
			cnt_nl(last_lst);
			if (last_lst->leng == 0)
				last_lst->is_eof = TRUE;
			return (*lst);
		}
	}
	return (NULL);
}

char	*get_line(t_bufflst **lst)
{
	size_t		len_line;
	size_t		idx;
	t_bufflst	*temp;

	len_line = 0;
	idx = 0;
	temp = *lst;
	while (temp->num_nl == 0 && temp->is_eof == FALSE)
	{
		len_line += temp->leng;
		temp = temp->next;
	}
	while (*(temp->st_buff + idx) != '\n' && *(temp->st_buff + idx))
		idx++;
	len_line += idx;
	if (temp->leng > 0)
		temp->leng -= ++idx;
	return (buffcat(lst, len_line));
}

char	*buffcat(t_bufflst **lst, size_t len_line)
{
	size_t		idx;
	char		*line;

	idx = 0;
	line = (char *)malloc((len_line + 1) * sizeof(char));
	if (line == NULL)
		free_lst(lst, FREE_ALL);
	else
	{
		while ((*lst)->num_nl == 0 && (*lst)->is_eof == FALSE)
		{
			while (*((*lst)->st_buff) != '\0')
				*(line + idx++) = *((*lst)->st_buff++);
			free_lst(lst, FREE_ONE);
		}
		while (*((*lst)->st_buff) != '\n' && *((*lst)->st_buff))
			*(line + idx++) = *((*lst)->st_buff++);
		*(line + idx++) = '\0';
		if ((*lst)->num_nl != 0)
			(*lst)->num_nl--;
		if (*((*lst)->st_buff) == '\n')
			(*lst)->st_buff++;
	}
	return (line);
}
