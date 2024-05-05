/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsarmada <nsarmada@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 13:37:51 by nsarmada      #+#    #+#                 */
/*   Updated: 2024/05/05 16:38:44 by nsarmada      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	word_count(char *command, char c)
{
	int		i;
	int		words;

	words = 1;
	i = 0;
	while (command[i])
	{
		if (command[i] == c && (command[i - 1] >= 97 && command[i - 1] <= 122))
			words++;
		i++;
	}
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

char	*split_command(char *command, t_cmd_x *cmd)
{
	int		i;
	int		j;
	char	**split_cmd;

	i = 0;
	j = 0;
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
	free(split_cmd);
	return (cmd->cmd);
}
