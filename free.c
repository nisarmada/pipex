/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 19:06:00 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/18 19:20:27 by nsarmada      ########   odam.nl         */
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
