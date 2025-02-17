/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <oyozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:21:55 by oyozcan           #+#    #+#             */
/*   Updated: 2024/05/14 10:21:56 by oyozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export(void)
{
	char	**export;

	export = g_ms.export;
	while (*export)
	{
		printf("declare -x %s\n", *export);
		export++;
	}
	if (is_child())
		exit (EXIT_SUCCESS);
}
