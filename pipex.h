/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 19:06:23 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/05/05 16:44:24 by nsarmada      ########   odam.nl         */
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

typedef struct t_cmd_x
{
	char	*path;
	char	*cmd;
	char	**args;
	int		f;
}	t_cmd_x;

char	**get_path(char **envp);
char	*find_correct_path(char **envp);
int		word_count(char *command, char c);
char	*split_command(char *command, t_cmd_x *cmd);
char	**possible_paths(char **paths, t_cmd_x cmd);
void	pipex(char **envp, char **av, int f1, int f2);
char	*ft_strconcat2(const char *str, const char *buffer);
// void	init_cmd (t_cmd_x *cmd, int f);
void	free_path(char **path);
void	exec_cmd(t_cmd_x cmd, t_cmd_x cmd2, char **envp);
void	child_process_1(t_cmd_x cmd, char *envp[], int fd[]);
void	child_process_2(t_cmd_x cmd, char *envp[], int fd[]);
t_cmd_x	handler(t_cmd_x *cmd, int f, char *av, char *envp[]);
void	free_struct(t_cmd_x *cmd);
void	exec_cmd_2(t_cmd_x cmd2, int fd[], char *envp[]);

#endif 