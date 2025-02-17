/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:14:03 by oyozcan           #+#    #+#             */
/*   Updated: 2024/05/14 10:14:08 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_env(char *data)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = ft_calloc(sizeof(char *), env_len() + 1);
	while (g_ms.env[i])
	{
		if (ft_strncmp(g_ms.env[i], data, ft_strlen(data)))
		{
			new_env[j] = ft_strdup(g_ms.env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = 0;
	free_array(g_ms.env);
	g_ms.env = new_env;
}

void	remove_export(char *data)
{
	int		i;
	int		j;
	char	**new_export;

	i = 0;
	j = 0;
	new_export = ft_calloc(sizeof(char *), export_len() + 1);
	while (g_ms.export[i])
	{
		if (ft_strncmp(g_ms.export[i], data, ft_strlen(data)))
		{
			new_export[j] = ft_strdup(g_ms.export[i]);
			j++;
		}
		i++;
	}
	new_export[j] = 0;
	free_array(g_ms.export);
	g_ms.export = new_export;
}

void	builtin_unset(char **input)
{
	char	*data;

	input++;
	while (*input)
	{
		if (ft_strchr(*input, '='))
		{
			data = ft_strjoin(*input, "=");
			remove_env(data);
			remove_export(data);
		}
		else
		{
			data = ft_strdup(*input);
			remove_export(data);
			remove_env(data);
		}
		free(data);
		input++;
	}
	set_paths();
	if (is_child())
		exit (EXIT_SUCCESS);
}
