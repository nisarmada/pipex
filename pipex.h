/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 19:06:23 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/19 19:29:57 by nsarmada      ########   odam.nl         */
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
# include "../libft/libft.h"

typedef struct {
	char	*path;
	char	*cmd;
	char	**args;
	int		f;
}	cmd_x;

char **get_path(char **envp);
char *find_correct_path(char **envp);
int word_count(char *command, char c);
char *split_command(char *command, cmd_x *cmd);
char **possible_paths(char **paths, cmd_x cmd);
void pipex(char **envp, char **av, int f1, int f2);
char	*ft_strconcat2(const char *str, const char *buffer);
void init_cmd (cmd_x *cmd, int f);
void free_path(char **path);
void exec_cmd(cmd_x cmd, cmd_x cmd2, char **envp);
void child_process_1(cmd_x cmd, char* envp[], int fd[]);
void child_process_2(cmd_x cmd, char* envp[], int fd[]);
cmd_x handler(cmd_x *cmd, int f, char* av, char* envp[]);

#endif 