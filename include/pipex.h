/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 10:00:00 by aitawi            #+#    #+#             */
/*   Updated: 2026/08/22 10:00:00 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>

# define EXIT_NO_EXEC 126
# define EXIT_NOT_FOUND 127

# define MSG_NOT_FOUND "command not found"
# define MSG_NO_FILE "No such file or directory"
# define MSG_NO_PERM "Permission denied"
# define MSG_USAGE "usage: ./pipex file1 cmd1 cmd2 file2"

void	execute(char *cmd, char **envp);
void	free_split(char **split);
char	*resolve_cmd(char *cmd, char **envp, int *code);
void	print_error(char *arg, char *msg);
void	error_errno(char *arg);
int		fatal(char *context);
int		usage_error(void);
int		get_status(int status);

#endif
