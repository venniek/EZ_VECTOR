/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:41:48 by ygj               #+#    #+#             */
/*   Updated: 2021/10/02 12:44:35 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define ERR -1
# define FREE_ALL 1
# define FREE_ONE 0
# define TRUE 1
# define FALSE 0

typedef struct s_bufflst
{
	char				*buff;
	char				*st_buff;
	size_t				num_nl;
	ssize_t				leng;
	short				is_eof;
	struct s_bufflst	*next;
}				t_bufflst;

int				get_next_line(int fd, char **line);
void			cnt_nl(t_bufflst *lst);
t_bufflst		*malloc_lastlst(t_bufflst **lst);
t_bufflst		*find_lastlst(t_bufflst *lst);
t_bufflst		*rnadd_lst(int fd, t_bufflst **lst);
char			*get_line(t_bufflst **lst);
char			*buffcat(t_bufflst **lst, size_t len_line);
void			free_lst(t_bufflst **lst, short flg);
t_bufflst		*add_lastlst(t_bufflst **lst);

#endif
