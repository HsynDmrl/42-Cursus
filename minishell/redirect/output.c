/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <oyozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:17:56 by oyozcan           #+#    #+#             */
/*   Updated: 2024/05/14 10:17:58 by oyozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	output(char *file, int mode)
{
	int		fd;

	fd = 0;
	if (mode == REPLACE)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (mode == APPEND)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd == -1)
	{
		perror("minishell");
		if (!is_child())
			return ;
		else
			exit(errno);
	}
	dup2(fd, 1);
	close(fd);
}
