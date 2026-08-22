/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 10:00:00 by aitawi            #+#    #+#             */
/*   Updated: 2026/08/22 10:00:00 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

static char	*join_path(char *dir, char *cmd)
{
	char	*prefix;
	char	*full;

	prefix = ft_strjoin(dir, "/");
	if (!prefix)
		return (NULL);
	full = ft_strjoin(prefix, cmd);
	free(prefix);
	return (full);
}

static char	*search_path(char *cmd, char **envp)
{
	char	**dirs;
	char	*full;
	int		i;

	dirs = get_paths(envp);
	if (!dirs)
		return (NULL);
	i = 0;
	while (dirs[i])
	{
		full = join_path(dirs[i], cmd);
		if (full && access(full, X_OK) == 0)
		{
			free_split(dirs);
			return (full);
		}
		free(full);
		i++;
	}
	free_split(dirs);
	return (NULL);
}

char	*resolve_cmd(char *cmd, char **envp, int *code)
{
	char	*path;

	*code = EXIT_NOT_FOUND;
	if (!ft_strchr(cmd, '/'))
	{
		path = search_path(cmd, envp);
		if (!path)
			print_error(cmd, MSG_NOT_FOUND);
		return (path);
	}
	if (access(cmd, F_OK) != 0)
	{
		print_error(cmd, MSG_NO_FILE);
		return (NULL);
	}
	if (access(cmd, X_OK) != 0)
	{
		*code = EXIT_NO_EXEC;
		print_error(cmd, MSG_NO_PERM);
		return (NULL);
	}
	return (ft_strdup(cmd));
}
