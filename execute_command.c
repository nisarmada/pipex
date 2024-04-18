/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_command.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 20:33:28 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/18 20:49:58 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void exec_cmd(cmd_x cmd1, cmd_x cmd2, int f1, int f2, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	f1 = f1 + f2;
	pid1 = fork();
	if (pid1 < 0)
		return ;
	if (pid1 == 0)
	{
		execve(cmd1.path, cmd1.args, envp);
	}
	if (pid1 > 0)
	{
		wait (NULL);
		pid2 = fork();
		if (pid2 == 0)
			execve(cmd2.path, cmd2.args, envp);
		else
		{
			wait (NULL);
		}
	}
}