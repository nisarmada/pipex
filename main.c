/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 19:05:52 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/05/05 14:25:13 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	f1;
	int	f2;

	f1 = 0;
	f2 = 1;
	if (ac != 5)
		return (0);
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_CREAT | O_RDWR, 0644);
	if (f1 < 0)
		return (1);
	if (f2 < 0)
		return (2);
	pipex(envp, av, f1, f2);
	close (f1);
	close (f2);
}
