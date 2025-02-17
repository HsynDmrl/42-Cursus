/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:11:58 by oyozcan           #+#    #+#             */
/*   Updated: 2024/05/14 10:12:01 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_pwd(char **env, char *pwd, char *type)
{
	int		i;
	char	*new_env;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], type, ft_strlen(type)) == 0)
		{
			new_env = malloc(ft_strlen(pwd) + ft_strlen(type) + 1);
			if (new_env)
			{
				ft_strcpy(new_env, type);
				ft_strcat(new_env, pwd);
				free(pwd);
				free(env[i]);
				env[i] = new_env;
			}
			break ;
		}
		i++;
	}
}

void	set_pwd(void)
{
	change_pwd(g_ms.env, get_env("PWD"), "OLDPWD=");
	change_pwd(g_ms.env, getcwd(NULL, 0), "PWD=");
}

void	check_tilde(char *input, char *home)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(input, '/');
	if (home && *home)
	{
		if (chdir(home))
			perror("minishell ");
	}
	while (temp[i])
	{
		i++;
		if (!temp[i])
			break ;
		if (chdir(temp[i]) != 0)
		{
			errno = 1;
			write(2, "minishell : No such file or directory\n", 38);
			strerror(errno);
		}
	}
	free_array(temp);
}

void	builtin_cd(char **input)
{
	char	*home;

	home = getenv("HOME");
	if (input[1] == NULL)
	{
		if (home && *home)
		{
			if (chdir(home))
				perror("minishell ");
		}
	}
	else
	{
		if (input[1][0] == '~')
			check_tilde(input[1], home);
		else if (chdir(input[1]) != 0)
		{
			errno = 1;
			write(2, "minishell : No such file or directory\n", 38);
			strerror(errno);
		}
	}
	set_pwd();
	if (is_child())
		exit (errno);
}
