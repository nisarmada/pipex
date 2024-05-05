/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 19:06:00 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/05/05 16:53:35 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **path)
{
	int	i;

	i = 0;
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

void	free_struct(t_cmd_x *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
	free(cmd->args);
}

void	check_empty(char *av[])
{
	if (av[1] == NULL || av[4] == NULL)
		ft_printf("zsh: no such file or directory:\n");
	if (av[3] == NULL || av[2] == NULL)
		ft_printf("zsh: permission denied\n");
}
