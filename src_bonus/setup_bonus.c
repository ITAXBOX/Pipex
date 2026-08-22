/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 10:00:00 by aitawi            #+#    #+#             */
/*   Updated: 2026/08/22 10:00:00 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	parse_args(t_pipex *px, int argc, char **argv)
{
	px->heredoc = 0;
	px->first = 2;
	px->in = -1;
	px->out = -1;
	px->outfile = -1;
	px->last = -1;
	px->fd[0] = -1;
	px->fd[1] = -1;
	if (argc >= 5 && ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		px->heredoc = 1;
		px->first = 3;
	}
	else if (argc < 5)
		return (0);
	px->count = argc - px->first - 1;
	return (1);
}

int	open_infile(t_pipex *px, char **argv)
{
	int	fd;

	if (px->heredoc)
		return (heredoc_fd(argv[2]));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_errno(argv[1]);
	return (fd);
}

int	open_outfile(t_pipex *px, char **argv, int argc)
{
	int	fd;

	if (px->heredoc)
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error_errno(argv[argc - 1]);
	return (fd);
}

int	wait_all(pid_t last)
{
	int		status;
	int		code;
	pid_t	pid;

	code = EXIT_FAILURE;
	pid = wait(&status);
	while (pid != -1)
	{
		if (pid == last)
			code = get_status(status);
		pid = wait(&status);
	}
	return (code);
}
