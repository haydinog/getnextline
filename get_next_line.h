/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.com.tr>  #+#  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-16 09:23:26 by haydinog          #+#    #+#             */
/*   Updated: 2026-02-16 09:23:26 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE  42

#endif

#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);



#endif
