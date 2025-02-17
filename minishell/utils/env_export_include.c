/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_include.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <oyozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:18:37 by oyozcan           #+#    #+#             */
/*   Updated: 2024/05/14 10:18:39 by oyozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_include_env(char *str)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	env = g_ms.env;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (-1);
}

int	is_include_export(char *str)
{
	int		i;
	int		j;
	char	**export;

	i = 0;
	export = g_ms.export;
	while (export[i])
	{
		j = 0;
		while (export[i][j] && str[j])
		{
			if (str[j] == '=' && export[i][j] == '=')
				return (i);
			if (str[j] != export[i][j])
				break ;
			j++;
			if (export[i][j] == '\0')
				return (i);
		}
		i++;
	}
	return (-1);
}
