/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:40:27 by haydinog          #+#    #+#             */
/*   Updated: 2026/02/22 13:10:23 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int		i;
	if (!s)
		return(NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return (NULL);
}
char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(s);
	dest = malloc(sizeof (char ) * len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *free_stash(char *stash)
{
	if(stash)
	{
	free(stash);
	stash = NULL;
	}
	return(NULL);
}
char *free_buffer(char *buffer)
{
	free(buffer);
	return(NULL);
}