/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/01 15:26:39 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/18 20:49:00 by nsarmada      ########   odam.nl         */
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
	//printf("env %s\n", envp[i]);
	split_path = ft_split(envp[i], ':');
	if (!split_path)
	{
		free(split_path);
		return (NULL);
	}
	i = 0;
	// while (split_path[i])
	// {
	// 	printf("split path %s\n", split_path[i]);
	// 	i++;
	// }
	//printf("i %i\n", i);
	return (split_path);
}
char **possible_paths(char **paths, char *command)
{
	int		i;
	char	**connected_path;
	//char	*correct_path;
	int		j;
	
	i = 0;
	j = 0;
	
	while (paths[j])
		j++;
	connected_path = (char **)malloc(sizeof(char *) * (j + 2));
	while (i <= j)
	{
		connected_path[i] = NULL;
		i++;
	}
	i = 0;
	if (!connected_path)
		return NULL;
	while (paths[i] != NULL)
	{
		connected_path[i] = ft_strconcat2(paths[i], command);
		//printf("connected path : %s\n", connected_path[i]);
		i++;
	}
	//printf("heyy\n");
	connected_path[i] = NULL;
	//correct_path = find_correct_path(connected_path, command);
	return (connected_path);
}

char *find_correct_path(char **paths)
{
	int		i = 0;
	char	*correct_path;

	i = 0;
	correct_path = NULL;
	while (paths[i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			correct_path = paths[i];
			break;
		}
		i++;
	}
	// printf("i : %i\n", i);
	//printf("corerct path %s\n", paths[i]);
	return (correct_path);
}

void pipex(char **envp, char **av, int f1, int f2)
{
	int		i;
	cmd_x	cmd1;
	cmd_x	cmd2;
	char	**cmd1_before = NULL;
	char	**cmd2_before = NULL;
	char	**path_before;
	char	**path_after;
	char	*correct_path;
	
	i = 0;
	init_cmd(&cmd1, f1);
	init_cmd(&cmd2, f2);
	cmd1_before = (char **)malloc(sizeof(char *) * (10));
	cmd2_before = (char **)malloc(sizeof(char *) * (10));
	// cmd1_before = split_command(av[2], &cmd1);
	// cmd2_before = split_command(av[3], &cmd2);
	cmd1.cmd = split_command(av[2], &cmd1);
	cmd2.cmd = split_command(av[3], &cmd2);
	//printf("lalala %s\n", cmd1.cmd);
	path_before = get_path(envp);
	//printf("in pipex %s\n", cmd1[0]);
	path_after = possible_paths(path_before, cmd1.cmd);
	correct_path = find_correct_path(path_after);
	// free_path(path_after);
	// free_path(path_before);
	printf("correct path : %s\n", correct_path);
	while (cmd1.args[i])
	{
		printf("cmd args %s\n", cmd1.args[i]);
		i++;
	}
	exec_cmd(cmd1, cmd2, f1, f2, envp);
	//free_path(cmd1_before);
	//printf("cmd args %s\n", cmd1.args[i]);
}
