/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:48:45 by egiles            #+#    #+#             */
/*   Updated: 2019/11/16 14:19:59 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("\n");
	while ((i = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		printf("gnl ret - %d\n", i);
		free(line);
	}
	if (line)
		free(line);
	printf("gnl ret - %d\n", i);
	return (0);
}
