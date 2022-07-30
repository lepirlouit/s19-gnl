/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:20:20 by bde-biol          #+#    #+#             */
/*   Updated: 2022/07/30 17:48:37 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

ssize_t	ft_strchr(const char *s, int c)
{
	ssize_t	position;

	position = 0;
	while (s[position])
	{
		if ((char)s[position] == (char)c)
			return (position);
		position++;
	}
	if (c == 0)
		return (position);
	return (-1);
}

ssize_t	concat_and_read(int fd, char **file_content)
{
	char	*buffer;
	ssize_t	number_of_bytes_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	number_of_bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (number_of_bytes_read == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[number_of_bytes_read] = 0;
	temp = *file_content;
	*file_content = malloc((ft_strlen(*file_content)
				+ number_of_bytes_read + 1) * sizeof(char));
	if (!*file_content)
	{
		free(temp);
		free(buffer);
		return (0);
	}
	ft_strcpy(*file_content, temp);
	ft_strcat(*file_content, buffer);
	free(temp);
	free(buffer);
	return (number_of_bytes_read);
}

char	*replace_content_and_return(char **file_content)
{
	ssize_t	position;
	char	*line;
	char	*temp;

	position = ft_strchr(*file_content, '\n');
	if (position == -1)
		position = ft_strlen(*file_content) - 1;
	line = ft_substr(*file_content, 0, position + 1);
	temp = *file_content;
	*file_content = ft_substr(*file_content, position + 1,
			ft_strlen(*file_content) - position - 1);
	free(temp);
	return (line);
}

/*while file content doesn't contain \n and read from file is > 0*/
char	*get_next_line(int fd)
{
	static char	*file_content[MAX_OPEN_FILES];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	if (!file_content[fd])
		file_content[fd] = malloc_empty_string();
	while (ft_strchr(file_content[fd], '\n') == -1
		&& concat_and_read(fd, &file_content[fd]) > 0)
		;
	if (!ft_strlen(file_content[fd]))
		return (NULL);
	return (replace_content_and_return(&file_content[fd]));
}
