/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:59:18 by bde-biol          #+#    #+#             */
/*   Updated: 2022/07/30 12:04:54 by bde-biol         ###   ########.fr       */
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
	int			fd;
	const char	*path;
	char		*line;

	printf("String length of HelloWorld : %ld\n", ft_strlen("HelloWorld"));
	printf("Postion of \\n in Hello\\nWorld : %ld\n",
		ft_strchr("Hello\nWorld", '\n'));
	if (argc > 0)
	{
	path = argv[1];
	fd = open_file(path);
		if (fd == -1)
			return (0);
		line = get_next_line(fd);
		printf("line : %s\n", line);
		free(line);
		line = get_next_line(fd);
		printf("line : %s\n", line);
		free(line);
		close(fd);
	}
	return (0);
}
