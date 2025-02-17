/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <oyozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:18:52 by oyozcan           #+#    #+#             */
/*   Updated: 2024/05/14 10:18:53 by oyozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	swap_export(int pos, char *input)
{
	char	*temp;

	temp = g_ms.export[pos];
	g_ms.export[pos] = ft_strdup(input);
	free(temp);
}

void	swap_env(int pos, char *input)
{
	char	*temp;

	temp = g_ms.env[pos];
	g_ms.env[pos] = ft_strdup(input);
	free(temp);
}
