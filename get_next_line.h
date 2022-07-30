/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:20:08 by bde-biol          #+#    #+#             */
/*   Updated: 2022/07/30 17:51:54 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define MAX_OPEN_FILES 4096

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src,
			size_t dstsize);
ssize_t	ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*malloc_empty_string(void);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*join_and_free_s1(char *s1, char*S2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

#endif
