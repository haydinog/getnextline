/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.com.tr>  #+#  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-16 09:23:02 by haydinog          #+#    #+#             */
/*   Updated: 2026-02-16 09:23:02 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

static char *buffer_to_stash(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	char *newstash;
	i = 0;
	j = 0;
	
	if(!stash || !buffer)
		return (NULL);
	newstash = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!newstash)
		return (NULL);
	while (stash && stash[i])
	{
		newstash[i] = stash[i];
		i++;
	}
	while(buffer && buffer[j])
	{
		newstash[i] = buffer[j];
		i++;
		j++;
	}
	newstash[i] = '\0';
	free(stash);
	return(newstash);
}

static char *stash_to_line(char *stash)
{
	size_t	i;
	size_t	j;
	char *line;

	i = 0;
	j= 0;
	if (!stash || !stash[0])
		return(NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);

	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return(line);
}
char *get_next_line(int fd)
{
	static char *stash;
	char		*buffer;
	char		*line;
	int			value;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!stash || !ft_strchr(stash, '\n')) // bu while detaylı read fonksiyonu olacak
	{
		value = read(fd, buffer, BUFFER_SIZE);
		if (value <= 0)
		{
			free(buffer);
			return(NULL);
		}
		if (value == 0)
			break;
		buffer[value] = '\0';	
	}
	stash = buffer_to_stash(stash, buffer);
		if(!stash)
			return (NULL);
	line = stash_to_line(stash);
	return(line);	
}

