/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 10:00:00 by aitawi            #+#    #+#             */
/*   Updated: 2026/08/22 10:00:00 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*path;
	int		code;

	args = ft_split(cmd, ' ');
	if (!args)
		exit(fatal("malloc"));
	if (!args[0])
	{
		free_split(args);
		print_error(cmd, MSG_NOT_FOUND);
		exit(EXIT_NOT_FOUND);
	}
	path = resolve_cmd(args[0], envp, &code);
	if (!path)
	{
		free_split(args);
		exit(code);
	}
	execve(path, args, envp);
	error_errno(path);
	free(path);
	free_split(args);
	exit(EXIT_NO_EXEC);
}
