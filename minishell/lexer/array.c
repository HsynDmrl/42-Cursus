/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <oyozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:17:11 by oyozcan           #+#    #+#             */
/*   Updated: 2024/05/14 10:17:14 by oyozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**push_array(char **arg_arr, char *str)
{
	int		i;
	int		len;
	char	**new_arr;

	i = 0;
	len = 0;
	while (arg_arr && arg_arr[len])
		len++;
	new_arr = ft_calloc(sizeof(char *), len + 2);
	while (i < len)
	{
		new_arr[i] = arg_arr[i];
		i++;
	}
	new_arr[i] = str;
	free(arg_arr);
	return (new_arr);
}
