/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 10:00:00 by aitawi            #+#    #+#             */
/*   Updated: 2026/08/22 10:00:00 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	child(t_pipex *px, char *cmd, char **envp)
{
	if (px->fd[0] != -1)
		close(px->fd[0]);
	if (px->outfile != -1 && px->outfile != px->out)
		close(px->outfile);
	if (px->in == -1 || px->out == -1)
	{
		if (px->in != -1)
			close(px->in);
		if (px->out != -1)
			close(px->out);
		exit(EXIT_FAILURE);
	}
	dup2(px->in, STDIN_FILENO);
	dup2(px->out, STDOUT_FILENO);
	close(px->in);
	close(px->out);
	execute(cmd, envp);
}

static int	open_next(t_pipex *px, int index)
{
	px->fd[0] = -1;
	px->fd[1] = -1;
	if (index == px->count - 1)
	{
		px->out = px->outfile;
		return (0);
	}
	if (pipe(px->fd) == -1)
		return (fatal("pipe"));
	px->out = px->fd[1];
	return (0);
}

static void	close_step(t_pipex *px)
{
	if (px->in != -1)
		close(px->in);
	if (px->fd[1] != -1)
		close(px->fd[1]);
	px->in = px->fd[0];
}

static int	run_pipeline(t_pipex *px, char **argv, char **envp)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < px->count)
	{
		if (open_next(px, i) != 0)
			return (EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
		{
			close_step(px);
			return (fatal("fork"));
		}
		if (pid == 0)
			child(px, argv[px->first + i], envp);
		px->last = pid;
		close_step(px);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	int		code;
	int		status;

	if (!parse_args(&px, argc, argv))
		return (usage_error());
	px.in = open_infile(&px, argv);
	px.outfile = open_outfile(&px, argv, argc);
	code = run_pipeline(&px, argv, envp);
	if (px.outfile != -1)
		close(px.outfile);
	if (px.in != -1)
		close(px.in);
	status = wait_all(px.last);
	if (code != 0)
		return (code);
	return (status);
}

/*
========================
BONUS 1 - MULTIPLE PIPES
========================

./pipex infile "cat" "grep a1" "wc -l" outfile

./pipex infile "cat" "grep hello" "sort" "wc -l" outfile

./pipex infile "/bin/cat" "/usr/bin/grep a1" "/usr/bin/wc -w" outfile

./pipex infile "badcmd" "cat" "wc -l" outfile

./pipex infile "cat" "badcmd" "wc -l" outfile

./pipex infile "cat" "wc -l" "badcmd" outfile
echo $?

valgrind --leak-check=full --track-fds=yes
./pipex infile "cat" "grep a1" "wc -l" outfile
*/

/*
================
BONUS 2 - HEREDOC
================

./pipex here_doc END "cat" "wc -l" outfile

./pipex here_doc STOP "grep hello" "wc -w" outfile

./pipex here_doc END "cat" "grep a1" "wc -l" outfile

./pipex here_doc END "badcmd" "wc -l" outfile

./pipex here_doc END "cat" "badcmd" outfile
echo $?

echo "OLD DATA" > outfile
./pipex here_doc END "cat" "wc -l" outfile
cat outfile

valgrind --leak-check=full --track-fds=yes
./pipex here_doc END "cat" "wc -l" outfile
*/
