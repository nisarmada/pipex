/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 13:37:51 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/04/19 20:47:44 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int word_count(char *command, char c)
{
	int		i;
	int		words;

	words = 1;
	i = 0;
	//printf("command %s\n", command);
	while (command[i])
	{
		if (command[i] == c && (command[i - 1] >= 97 && command[i - 1] <= 122))
			words++;
		i++;
	}
	//printf("words %i\n", words);
	return (words);
}
char	*ft_strconcat2(const char *str, const char *buffer)
{
	size_t	i;
	size_t	n;
	char	*ptr;

	i = 0;
	n = 0;
	ptr = (char *)malloc(ft_strlen(str) + ft_strlen(buffer) + 2);
	if (!ptr)
		return (free_secure(&ptr));
	if (!str || !buffer)
		return (NULL);
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i++] = '/';
	while (buffer[n] != '\0')
	{
		ptr[i + n] = buffer[n];
		n++;
	}
	ptr[i + n] = '\0';
	return (ptr);
}

char *split_command(char *command, cmd_x *cmd)
{
	int		i;
	int		j = 0;
	char	**split_cmd;

	i = 0;
	split_cmd = ft_split(command, ' ');
	cmd->cmd = split_cmd[0];
	while (split_cmd[j] != NULL)
		j++;
	cmd->args = (char **)malloc(sizeof(char *) * (j + 1));
	if (!cmd->args)
		exit(EXIT_FAILURE);
	cmd->args[0] = split_cmd[0];
	i = 1;
	while (i <= j)
	{
		cmd->args[i] = split_cmd[i];
		i++;
	}
	printf("command %s\n", cmd->args[0]);
	free(split_cmd);
	//cmd->args[i] = NULL;
	return (cmd->cmd);
}

void init_cmd (cmd_x *cmd, int f)
{
	cmd->f = f;
	cmd->path = NULL;
	cmd->cmd = NULL;
	cmd->args = NULL;
}