/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:23:21 by egiles            #+#    #+#             */
/*   Updated: 2019/11/16 14:08:07 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <libc.h>
# include <stdlib.h>

# define BUFF_SIZE 100

typedef struct			s_gnl
{
	int					fd_lst;
	char				*buff;
	struct s_gnl		*next;
}						t_gnl;

int						get_next_line(const int fd, char **line);

#endif
