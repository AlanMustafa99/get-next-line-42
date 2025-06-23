/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amustafa <amustafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:38:30 by amustafa          #+#    #+#             */
/*   Updated: 2025/06/20 18:35:06 by amustafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*handle_read_error(char *buf, char *stash)
{
	free(buf);
	free(stash);
	return (NULL);
}

static char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	ssize_t	r;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (handle_read_error(NULL, stash));
	r = 1;
	while (!ft_strchr(stash, '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (handle_read_error(buf, stash));
		if (r == 0)
			break ;
		buf[r] = '\0';
		tmp = ft_strjoin(stash, buf);
		if (!tmp)
			return (handle_read_error(buf, stash));
		free(stash);
		stash = tmp;
	}
	free(buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	int		len;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	new = malloc(ft_strlen(stash + i) + 1);
	if (!new)
		return (free(stash), NULL);
	j = 0;
	while (stash[i + j])
	{
		new[j] = stash[i + j];
		j++;
	}
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}
