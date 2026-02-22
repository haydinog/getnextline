/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:23:02 by haydinog          #+#    #+#             */
/*   Updated: 2026/02/22 20:15:07 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

static char *buffer_to_stash(char *stash, char *buffer)
{
	int		i;
	int		j;
	char *newstash;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	if (!stash)	
		return (stash = ft_strdup(buffer));
	newstash = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!newstash)
		return (free_stash(stash));
	while (stash[i]) 
	{
		newstash[i] = stash[i];
		i++;
	}
	while(buffer[j])
	newstash[i++] = buffer[j++];
	newstash[i] = '\0';
	free(stash);
	return(newstash);
}

static char *stash_to_line(char *stash)
{
	int		i;
	int		j;
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
static char *after_line(char *stash)
{
	int		i;
	int		j;
	char *last_stash;
	
	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
		else
			return(free_stash(stash));
	last_stash = malloc(ft_strlen(stash + i) + 1);
	if (!last_stash)
		return (free_stash(stash));
	while(stash[i])
		last_stash[j++] = stash[i++];
	last_stash[j] = '\0';
	free(stash);
	return(last_stash);
}

static char *read_buffer(int fd, char *stash)
{
	char *buffer;
	int value;
	
	while (!stash || !ft_strchr(stash, '\n'))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return(free_buffer(buffer));
		value = read(fd, buffer, BUFFER_SIZE);
		if (value == - 1)
		{
			free(buffer);
			return(free_stash(stash));
		}
		if (value == 0)
		{
			free(buffer);
			break;
		}
		buffer[value] = '\0';
		stash = buffer_to_stash(stash, buffer);
		free(buffer);
	}
	return(stash);
}
char *get_next_line(int fd)
{
	static char *stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_buffer(fd, stash);
	if(!stash || !stash[0])
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = stash_to_line(stash);
	if (!line)
	{
		free_stash(stash);
		stash = NULL;
		return(NULL);
	}
	stash = after_line(stash);
	return(line);	
}
// #include <stdio.h>
// int main()
// {
// 	int fd;
// 	fd = open("deneme.txt", O_RDWR);
// 	char *str;

// 	while((str = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 	}
		
	
// 	close(fd);
// }
