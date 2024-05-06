/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 19:06:00 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/05/06 15:38:27 by nsarmada      ########   odam.nl         */
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

int	check_empty(char *av[])
{
	if (av[1][0] == '\0' || av[4][0] == '\0' ||
	av[1][0] == ' ' || av[4][0] == ' ')
	{
		ft_printf("zsh: no such file or directory:\n");
		exit(EXIT_FAILURE);
	}
	if (av[3][0] == '\0' || av[2][0] == '\0')
	{
		ft_printf("zsh: permission denied\n");
		exit(EXIT_FAILURE);
	}
	if (av[2][0] == ' ' || av[3][0] == ' ')
	{
		ft_printf("zsh: command not found:\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
