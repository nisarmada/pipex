/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 19:05:52 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/12 17:24:07 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int ac, char **av, char **envp)
{
	char	*cmd;
	int		f1;
	int		f2;

	if (ac != 5)
		return 0;
	cmd = av[1];
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[3], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		return (1);
	if (f2 < 0)
		return (2);
	get_path(envp);
	
}