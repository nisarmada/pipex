/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 19:05:52 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/05/06 14:42:18 by nsarmada      ########   odam.nl         */
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
	{
		ft_printf("Invalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
	{
		perror("zsh");
		exit(EXIT_FAILURE);
	}
	if (check_empty(av) > 0)
		exit(EXIT_FAILURE);
	pipex(envp, av, f1, f2);
	close (f1);
	close (f2);
}
