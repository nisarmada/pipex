/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/01 15:26:39 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/12 20:09:06 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

char **get_path(char **envp)
{
	int		i;
	char	**split_path;
	
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
	{
		i++;
	}
	envp[i] = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	printf("env %s\n", envp[i]);
	split_path = ft_split(envp[i], ':');
	if (!split_path)
	{
		free(split_path);
		return (NULL);
	}
	i = 0;
	while (split_path[i])
	{
		printf("%s\n", split_path[i]);
		i++;
	}
	return (split_path);
}

char *find_correct_path(char **envp, char *command)
{
	int		i = 0;

	i = 0;
	while (envp[i])
	{
		if (!access(envp[i]))
		{
			i++;
		}
		break;
	}
	printf("%s\n", envp[i]);
}

char *get_command(char *command)
{
	int		i;
	char	*cmd;
}