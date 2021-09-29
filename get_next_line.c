/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:23:12 by egiles            #+#    #+#             */
/*   Updated: 2019/11/16 14:18:12 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*create_fd_lst(int fd)
{
	static t_gnl	*head;
	t_gnl			*tmp;
	t_gnl			*new;

	tmp = head;
	while (tmp)
	{
		if (tmp->fd_lst == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->buff = ft_memalloc(1);
	new->fd_lst = fd;
	new->next = head;
	head = new;
	return (new);
}

static void			create_line(char **line, t_gnl *lst)
{
	size_t	nchar;
	char	*tmp;

	if ((tmp = ft_strchr(lst->buff, '\n')))
		nchar = tmp - lst->buff;
	else
		nchar = ft_strchr(lst->buff, '\0') - lst->buff;
	tmp = *line;
	*line = ft_strsub(lst->buff, 0, nchar);
	(*line)[nchar] = '\0';
	free(tmp);
	tmp = lst->buff;
	lst->buff = ft_strsub(lst->buff, nchar + 1, (ft_strlen(lst->buff) - nchar));
	free(tmp);
}

static int			read_line(int fd, char **line)
{
	t_gnl			*lst;
	ssize_t			nbread;
	char			*buff;
	char			*tmp;

	nbread = 0;
	lst = create_fd_lst(fd);
	buff = (char *)malloc(BUFF_SIZE + 1);
	while (!(ft_strchr(lst->buff, '\n')) &&
	((nbread = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[nbread] = '\0';
		tmp = lst->buff;
		lst->buff = ft_strjoin(lst->buff, buff);
		free(tmp);
		if ((ft_strchr(buff, '\n')))
			break ;
	}
	free(buff);
	if (nbread < 0)
		return (-1);
	if (!nbread && !(*(lst->buff)))
		return (0);
	create_line(line, lst);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	if ((fd < 0) || !line || BUFF_SIZE < 1)
		return (-1);
	*line = ft_memalloc(1);
	return (read_line(fd, line));
}
