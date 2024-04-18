/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 19:05:52 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/18 20:31:02 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int ac, char **av, char **envp)
{
	//char	*cmd1;
	//char	*cmd2;
	//char	**command;
	int		f1;
	int		f2;

	if (ac != 5)
		return 0;
	// cmd1 = av[2];
	// cmd2 = av[3];
	printf("heyy\n");
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[3], O_CREAT | O_RDWR, 0644);
	if (f1 < 0)
		return (1);
	if (f2 < 0)
		return (2);
	printf("heyy\n");
	// get_path(envp);
	// //find_correct_path(envp, "ls");
	// command = split_command(cmd1);
	// printf("path : %s\n", find_correct_path(possible_paths(get_path(envp), command[0])));
	// possible_paths(get_path(envp), command[0]);
	pipex(envp, av, f1, f2);
	
}