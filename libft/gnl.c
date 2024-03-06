/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:28:17 by klopez            #+#    #+#             */
/*   Updated: 2024/03/06 03:51:16 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlengnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_cut4stash(char *str, char stash[1024][BUFFER_SIZE + 1], int fd)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ft_strlcpygnl(tmp, str, BUFFER_SIZE + 1);
	ft_memsetgnl(stash[fd], '\0', BUFFER_SIZE + 1);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i += 1;
	while (tmp[i] != '\0' && j < BUFFER_SIZE)
		stash[fd][j++] = tmp[i++];
	free(tmp);
}

char	*ft_update4stash(char *buffer, char stash[1024][BUFFER_SIZE + 1],
		char *line, int fd)
{
	if (stash[fd] && !line)
		line = ft_strjoingnl(line, stash[fd]);
	ft_cut4stash(stash[fd], stash, fd);
	if (!line[0])
	{
		free(line);
		free(buffer);
		return (NULL);
	}
	line = ft_cutline(line, '\n');
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	stash[1024][BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	bytes = 1;
	line = NULL;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_memsetgnl(stash[fd], '\0', bytes), free(buff), NULL);
	if (ft_boolstrchr(stash[fd], '\n') == 1)
		return (line = ft_update4stash(buff, stash, line, fd));
	while (bytes > 0 && ft_memsetgnl(buff, '\0', BUFFER_SIZE + 1))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (stash[fd] && !line)
			line = ft_strjoingnl(line, stash[fd]);
		if (ft_boolstrchr(buff, '\n') == 1)
			return (line = ft_strjoingnl(line, buff), ft_cut4stash(buff, stash,
					fd), line = ft_cutline(line, '\n'), free(buff), line);
		line = ft_strjoingnl(line, buff);
	}
	if (bytes == 0)
		line = ft_update4stash(buff, stash, line, fd);
	return (line);
}
