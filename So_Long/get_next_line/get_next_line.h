/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:51:10 by hdemirel          #+#    #+#             */
/*   Updated: 2024/01/09 18:02:40 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
int			ft_check(char *storage);
char		*ft_line_maker(int fd, char *buf, char *storage);
char		*ft_last_line(char *line);
char		*get_next_line(int fd);

#endif