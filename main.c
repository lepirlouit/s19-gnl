/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:59:18 by bde-biol          #+#    #+#             */
/*   Updated: 2022/07/30 15:52:59 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	open_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	return (fd);
}

int	main(int argc, char const *argv[])
{
	int			fd[2];
	char		*line;
	int			line_number;
	char 		should_break;

	line_number = 0;
	should_break = 0;
	printf("String length of HelloWorld : %ld\n", ft_strlen("HelloWorld"));
	printf("Postion of \\n in Hello\\nWorld : %ld\n",
		ft_strchr("Hello\nWorld", '\n'));
	if (argc > 1)
	{
		fd[0] = open_file(argv[1]);
		fd[1] = open_file(argv[2]);
		if (fd[0] == -1  || fd[1] == -1)
			return (0);
		while (1)
		{
			line = get_next_line(fd[0]);
			printf("line %3d: %40s", line_number, line);
			should_break = !line || line[ft_strlen(line) - 1] != '\n';
			free(line);
			line = get_next_line(fd[1]);
			printf("line %3d: %40s|%40s", line_number++, "", line);
			should_break = should_break && (!line || line[ft_strlen(line) - 1] != '\n');
			free(line);
			if (should_break)
				break ;
		}
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}
