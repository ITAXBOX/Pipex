/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 10:00:00 by aitawi            #+#    #+#             */
/*   Updated: 2026/08/22 10:00:00 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *arg, char *msg)
{
	char	buffer[4096];

	ft_strlcpy(buffer, "pipex: ", sizeof(buffer));
	ft_strlcat(buffer, arg, sizeof(buffer));
	ft_strlcat(buffer, ": ", sizeof(buffer));
	ft_strlcat(buffer, msg, sizeof(buffer));
	ft_strlcat(buffer, "\n", sizeof(buffer));
	write(STDERR_FILENO, buffer, ft_strlen(buffer));
}

void	error_errno(char *arg)
{
	print_error(arg, strerror(errno));
}

int	fatal(char *context)
{
	error_errno(context);
	return (EXIT_FAILURE);
}

int	usage_error(void)
{
	ft_putendl_fd("pipex: invalid number of arguments", STDERR_FILENO);
	ft_putendl_fd(MSG_USAGE, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	get_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (EXIT_FAILURE);
}
