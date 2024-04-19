/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/01 15:26:39 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/19 21:54:30 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

char **get_path(char **envp)
{
	int		i;
	char	**split_path;
	
	// i = 0;
	// while (envp[i] != NULL)
	// {
	// 	printf("get path %s\n", envp[i]);
	// 	i++;
	// }
	// printf("YOOO\n");
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
	{
		//printf("get path %i %s\n",i , envp[i]);
		i++;
	}
	//printf("get path %s\n", envp[i]);
	// i = 0;
	// while (envp[i] != NULL)
	// {
	// 	printf("get path %s\n", envp[i]);
	// 	i++;
	// }
	envp[i] = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	//printf("env %s\n", envp[i]);
	split_path = ft_split(envp[i], ':');
	envp[i] = ft_strconcat("PATH=", envp[i]);
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
char **possible_paths(char **paths, cmd_x cmd)
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
	while (i < j)
	{
		connected_path[i] = ft_strconcat2(paths[i], cmd.cmd);
		//printf("connected path : %s\n", connected_path[i]);
		i++;
	}
	//printf("heyy\n");
	connected_path[i] = NULL;
	// i = 0;
	// while (i < j)
	// {
	// 	printf("possible paths %s\n", connected_path[i]);
	// 	i++;
	// }
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
cmd_x handler(cmd_x *cmd, int f, char* av, char* envp[])
{
	char	**cmd_before = NULL;
	char	**path_before;
	char	**path_after;

	cmd->f = f;
	cmd_before = (char **)malloc(sizeof(char *) * (10));
	cmd->cmd = split_command(av, cmd);
	//printf("command %s\n", cmd->cmd);
	path_before = get_path(envp);
	int i = 0;
	// while (path_before[i])
	// {
	// 	printf("%s path before %s\n", cmd->cmd, path_before[i]);
	// 	i++;
	// }
	path_after = possible_paths(path_before, *cmd);
	i = 0;
	// while (path_after[i])
	// {
	// 	printf("%s path after %s\n", cmd->cmd, path_after[i]);
	// 	i++;
	// }
	cmd->path = find_correct_path(path_after);
	//printf("bananannananana\n");
	//printf("correct path handler %s\n", find_correct_path(path_after));
	//printf("%s path %s\n",cmd->cmd, cmd->path);
	free(path_before);
	free(path_after);
	return (*cmd);
}
void pipex(char **envp, char **av, int f1, int f2)
{
	int		i;
	cmd_x	cmd1;
	cmd_x	cmd2;
	// char	**cmd1_before = NULL;
	// char	**cmd2_before = NULL;
	// char	**path_before;
	// char	**path_after;
	
	i = 0;
	init_cmd(&cmd1, f1);
	init_cmd(&cmd2, f2);
	//printf("vananana\n");
	printf("av3 %s\n", av[3]);
	cmd1 = handler(&cmd1, f1, av[2], envp);
	//printf("vananana\n");
	cmd2 = handler(&cmd2, f2, av[3], envp);
	while (cmd1.args[i])
	{
		//printf("cmd args %s\n", cmd1.args[i]);
		i++;
	}
	i = 0;
	//printf("correct path : %s\n", cmd2.path);
	while (cmd2.args[i])
	{
		//printf("cmd args %s\n", cmd2.args[i]);
		i++;
	}
	exec_cmd(cmd1, cmd2, envp);
	//free_path(cmd1_before);
	//printf("cmd args %s\n", cmd1.args[i]);
}
