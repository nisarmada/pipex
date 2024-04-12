/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 19:06:23 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/12 20:07:18 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "libft.h"

typedef struct {
	char	*path;
	char	*cmd;
	char	**args;
	int		nbr;
}	cmd_x;

char **get_path(char **envp);
char *find_correct_path(char **envp, char *command);


#endif 