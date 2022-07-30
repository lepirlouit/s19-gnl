/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:20:20 by bde-biol          #+#    #+#             */
/*   Updated: 2022/07/30 12:03:09 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	size;

	if (!str)
		return (0);
	size = 0;
	while (str[size])
		size++;
	return (size);
}

ssize_t	ft_strchr(const char *s, int c)
{
	ssize_t	position;

	if (!s)
		return (0);
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

char	*malloc_empty_string(void)
{
	char	*str;

	str = malloc(sizeof(char));
	str[0] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	max_len;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc_empty_string());
	max_len = ft_strlen(s + start);
	if (len < max_len)
		max_len = len;
	ptr = malloc(max_len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, max_len + 1);
	return (ptr);
}

int	concat_and_read(int fd, char **file_content)
{
	char	buffer[BUFFER_SIZE + 1];
	int		number_of_bytes_read;
	char	*temp;

	number_of_bytes_read = read(fd, buffer, BUFFER_SIZE);
	printf("number_of_bytes_read : %d\n", number_of_bytes_read);
	buffer[number_of_bytes_read] = 0;
	temp = *file_content;
	*file_content = malloc((ft_strlen(*file_content)
				+ number_of_bytes_read + 1) * sizeof(char));
	ft_strcpy(*file_content, temp);
	ft_strcat(*file_content, buffer);
	free(temp);
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
	printf("Position : %ld\n", position);
	line = ft_substr(*file_content, 0, position + 1);
	temp = *file_content;
	*file_content = ft_substr(*file_content, position + 1, ft_strlen(*file_content) - position - 1);
	printf("New Content [%s]\n", *file_content);
	free(temp);
	return (line);
}

/*while file content doesn't contain \n and read from file is > 0*/
char	*get_next_line(int fd)
{
	static char	*file_content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!file_content)
		file_content = malloc_empty_string();
	while (ft_strchr(file_content, '\n') == -1 && concat_and_read(fd, &file_content) > 0)
		;

	printf("strlen of file_content : %ld\n", ft_strlen(file_content));
	if (!ft_strlen(file_content))
		return (NULL);
	return (replace_content_and_return(&file_content));
	// concat/join file_content and what has been read from file(buffer)
	//after the while :
	// if file_content == 0 o *file_content == 0 return NULL
	// if file content contains '\n' create substring until \n + replace file_content with the rest + return the subsctring
	// return file_content
	//return (file_content);
}
