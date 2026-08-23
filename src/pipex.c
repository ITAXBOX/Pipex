/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 10:00:00 by aitawi            #+#    #+#             */
/*   Updated: 2026/08/22 10:00:00 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_one(char **argv, int *fd, char **envp)
{
	int	infile;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		close(fd[1]);
		error_errno(argv[1]);
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(infile);
	close(fd[1]);
	execute(argv[2], envp);
}

static void	child_two(char **argv, int *fd, char **envp)
{
	int	outfile;

	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		close(fd[0]);
		error_errno(argv[4]);
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(fd[0]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	first;
	pid_t	second;
	int		fd[2];
	int		status;

	if (argc != 5)
		return (usage_error());
	if (pipe(fd) == -1)
		return (fatal("pipe"));
	first = fork();
	if (first == -1)
		return (fatal("fork"));
	if (first == 0)
		child_one(argv, fd, envp);
	second = fork();
	if (second == -1)
		return (fatal("fork"));
	if (second == 0)
		child_two(argv, fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(first, NULL, 0);
	waitpid(second, &status, 0);
	return (get_status(status));
}

/*
MY TESTS

./pipex infile "grep a1" "wc -w" outfile
./pipex infile "cat" "wc -l" outfile
./pipex infile "/bin/cat" "/usr/bin/wc -w" outfile

./pipex nofile "cat" "wc -l" outfile
./pipex infile "badcmd" "wc -l" outfile
./pipex infile "cat" "badcmd" outfile

./pipex infile "false" "true" outfile
echo $?

./pipex infile "true" "false" outfile
echo $?

valgrind --leak-check=full 
--track-fds=yes ./pipex infile "grep a1" "wc -w" 
outfile
*/
