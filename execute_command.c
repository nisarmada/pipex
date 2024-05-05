/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_command.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 20:33:28 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/05/05 16:47:26 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_cmd_x cmd1, t_cmd_x cmd2, char **envp)
{
	pid_t	pid1;
	int		fd[2];
	int		status;

	status = 0;
	if (pipe(fd) < 0)
		return ;
	pid1 = fork();
	if (pid1 < 0)
		return ;
	if (pid1 == 0)
	{
		child_process_1(cmd1, envp, fd);
		exit(EXIT_SUCCESS);
	}
	else
		close(fd[1]);
	exec_cmd_2(cmd2, fd, envp);
	waitpid (pid1, &status, 0);
}

void	exec_cmd_2(t_cmd_x cmd2, int fd[], char *envp[])
{
	int		status;
	pid_t	pid2;

	status = 0;
	pid2 = fork();
	if (pid2 < 0)
		return ;
	if (pid2 == 0)
	{
		child_process_2(cmd2, envp, fd);
		exit(EXIT_SUCCESS);
	}
	else
		close(fd[0]);
	waitpid (pid2, &status, 0);
}

void	child_process_1(t_cmd_x cmd, char *envp[], int fd[])
{
	int	i;

	i = 0;
	close(fd[0]);
	while (cmd.args[i])
	{
		printf("cmd.args[i] child process 1 %s\n", cmd.args[i]);
		i++;
	}
	if ((dup2(cmd.f, STDIN_FILENO) < 0))
	{
		perror("dup2-child one");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup22");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	if (execve(cmd.path, cmd.args, envp) < 0)
	{
		perror("execve child one");
		exit(EXIT_FAILURE);
	}
}

void	child_process_2(t_cmd_x cmd, char *envp[], int fd[])
{
	int	i;

	close(fd[1]);
	i = 0;
	while (cmd.args[i])
	{
		printf("cmd.args[i] child process 2 %s\n", cmd.args[i]);
		i++;
	}
	if (dup2(cmd.f, STDOUT_FILENO) < 0)
	{
		perror("child 2 dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[0], STDIN_FILENO) < 0)
	{
		perror("child 2 dup2 input failed");
		exit(EXIT_FAILURE);
	}
	if (execve(cmd.path, cmd.args, envp) < 0)
	{
		perror("child 2 execve failed");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
}
