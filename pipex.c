/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/01 15:26:39 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/05/05 16:37:49 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	**split_path;
	char	*path_env;

	i = 0;
	split_path = NULL;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
	{
		i++;
	}
	path_env = ft_strdup(envp[i] + 5);
	if (path_env)
	{
		split_path = ft_split(path_env, ':');
		free(path_env);
	}
	if (!split_path)
	{
		free(split_path);
		return (NULL);
	}
	return (split_path);
}

char	**possible_paths(char **paths, t_cmd_x cmd)
{
	int		i;
	char	**connected_path;
	int		j;

	i = 0;
	j = 0;
	while (paths[j])
		j++;
	connected_path = (char **)malloc(sizeof(char *) * (j + 1));
	while (i <= j)
	{
		connected_path[i] = NULL;
		i++;
	}
	i = 0;
	if (!connected_path)
		return (NULL);
	while (i < j)
	{
		connected_path[i] = ft_strconcat2(paths[i], cmd.cmd);
		i++;
	}
	connected_path[i] = NULL;
	free_path(paths);
	return (connected_path);
}

char	*find_correct_path(char **paths)
{
	int		i;
	char	*correct_path;

	i = 0;
	correct_path = NULL;
	while (paths[i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			correct_path = paths[i];
			break ;
		}
		i++;
	}
	i = 0;
	while (paths[i])
	{
		if (paths[i] != correct_path)
			free(paths[i]);
		i++;
	}
	return (correct_path);
}

t_cmd_x	handler(t_cmd_x *cmd, int f, char *av, char *envp[])
{
	char	**path_before;
	char	**path_after;

	cmd->f = f;
	cmd->cmd = split_command(av, cmd);
	path_before = get_path(envp);
	path_after = possible_paths(path_before, *cmd);
	cmd->path = find_correct_path(path_after);
	if (cmd->path == NULL)
	{
		ft_printf("zsh: command not found %s\n", cmd->cmd);
		exit(EXIT_FAILURE);
	}
	free(path_after);
	return (*cmd);
}

void	pipex(char **envp, char **av, int f1, int f2)
{
	int		i;
	t_cmd_x	cmd1;
	t_cmd_x	cmd2;

	i = 0;
	cmd1 = handler(&cmd1, f1, av[2], envp);
	cmd2 = handler(&cmd2, f2, av[3], envp);
	exec_cmd(cmd1, cmd2, envp);
	free_struct(&cmd1);
	free_struct(&cmd2);
	free(cmd1.path);
	free(cmd2.path);
}
