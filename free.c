/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 19:06:00 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/21 18:46:05 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_path(char **path)
{
	int i = 0;

	if (path == NULL)
		return ;
	while (path[i] != NULL)
	{
		free (path[i]);
		i++;
	}
	if (path)
		free (path);
}

void free_struct(cmd_x *cmd)
{
	int i;

	i = 0;
	// if (cmd->cmd)
	// 	free(cmd->cmd);
	// if (cmd->f)
	// 	free(cmd->f);
	// while (cmd->path[i])
	// {
	// 	free(cmd->path[i]);
	// 	i++;
	// }

	while (cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
	free(cmd->args);
}
