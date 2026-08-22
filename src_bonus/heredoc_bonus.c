/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 10:00:00 by aitawi            #+#    #+#             */
/*   Updated: 2026/08/22 10:00:00 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*read_line(void)
{
	char	*line;
	char	*joined;
	char	buffer[2];

	line = ft_strdup("");
	if (!line)
		return (NULL);
	buffer[1] = '\0';
	while (read(STDIN_FILENO, buffer, 1) == 1)
	{
		if (buffer[0] == '\n')
			return (line);
		joined = ft_strjoin(line, buffer);
		free(line);
		line = joined;
		if (!line)
			return (NULL);
	}
	if (line[0] != '\0')
		return (line);
	free(line);
	return (NULL);
}

static void	write_heredoc(int fd, char *limiter)
{
	char	*line;
	size_t	len;

	len = ft_strlen(limiter) + 1;
	line = read_line();
	while (line)
	{
		if (ft_strncmp(line, limiter, len) == 0)
		{
			free(line);
			line = NULL;
		}
		else
		{
			ft_putendl_fd(line, fd);
			free(line);
			line = read_line();
		}
	}
	close(fd);
	exit(EXIT_SUCCESS);
}

int	heredoc_fd(char *limiter)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		error_errno("pipe");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		error_errno("fork");
		return (-1);
	}
	if (pid == 0)
	{
		close(fd[0]);
		write_heredoc(fd[1], limiter);
	}
	close(fd[1]);
	return (fd[0]);
}
