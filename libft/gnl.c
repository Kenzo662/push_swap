/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:28:17 by klopez            #+#    #+#             */
/*   Updated: 2023/12/18 19:19:03 by klopez           ###   ########.fr       */
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
	char		*buffer;
	static char	stash[1024][BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	bytes = 1;
	line = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_memsetgnl(stash[fd], '\0', bytes), free(buffer), NULL);
	if (ft_boolstrchr(stash[fd], '\n') == 1)
		return (line = ft_update4stash(buffer, stash, line, fd));
	while (bytes > 0 && ft_memsetgnl(buffer, '\0', BUFFER_SIZE + 1))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (stash[fd] && !line)
			line = ft_strjoingnl(line, stash[fd]);
		if (ft_boolstrchr(buffer, '\n') == 1)
			return (line = ft_strjoingnl(line, buffer), ft_cut4stash(buffer, stash,
					fd), line = ft_cutline(line, '\n'), free(buffer), line);
		line = ft_strjoingnl(line, buffer);
	}
	if (bytes == 0)
		line = ft_update4stash(buffer, stash, line, fd);
	return (line);
}
