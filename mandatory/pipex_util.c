/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:46:27 by test              #+#    #+#             */
/*   Updated: 2022/09/13 01:57:19 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(char ***args)
{
	unsigned long int	i;

	if (*args == NULL)
		return ;
	i = 0;
	while ((*args)[i] != NULL)
	{
		free((*args)[i]);
		i++;
	}
	free(*args);
}

void	pipex_init(t_pipex *pipex)
{
	pipex->outfile = 0;
	pipex->infile = 0;
	pipex->cmd_paths = NULL;
	pipex->cmd_file = NULL;
	pipex->cmds = NULL;
}

void	all_clear(t_pipex *pipex)
{
	if (pipex->cmd_paths)
		free_args(&pipex->cmd_paths);
	if (pipex->cmds)
		free_args(&pipex->cmds);
	if (pipex->cmd_file != NULL)
		free(pipex->cmd_file);
	close(pipex->outfile);
	close(pipex->infile);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
}

void	perror_exit(char *msg, int status, t_pipex *pipex)
{
	perror(msg);
	all_clear(pipex);
	exit(status);
}

void	error_exit(char *msg, int status, t_pipex *pipex)
{
	ft_putendl_fd(msg, 2);
	all_clear(pipex);
	exit(status);
}
