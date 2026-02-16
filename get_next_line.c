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

#include "get_next_line.h"

char *get_next_line(int fd)
{
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	//byteread -1 ise hata (free ve null dönmeli)
	//byteread 0 ise  dosya bitti demek break atılabilir
	// N bukundu veya dosya bitti koşuluda kontrol edilmeli n i bulmak icin strchr kullanılabilir
}
int main()
{
	int fd;
	fd = open("deneme.txt",  O_CREAT | O_RDWR, 0777);
	
}