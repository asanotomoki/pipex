/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:45 by test              #+#    #+#             */
/*   Updated: 2022/09/13 02:02:21 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sysexits.h>
# include "libft.h"

# define ERR_CMD_PATH "Failed to get command path"
# define ERR_PAR_CMD "Parent process Command not found"
# define ERR_CHI_CMD "Child process Command not found"

typedef struct s_pipex
{
	int		pipefd[2];
	int		outfile;
	int		infile;
	char	**cmd_paths;
	char	*cmd_file;
	char	**cmds;
}	t_pipex;
int		pipex(t_pipex pipex, char **argv, char **envp);
void	child_process(t_pipex pipex, char *cmd, char **envp);
void	parent_process(t_pipex pipex, char *cmd, char **envp);
void	free_args(char ***args);
void	pipex_init(t_pipex *pipex);
void	error_exit(char *msg, int status, t_pipex *pipex);
void	perror_exit(char *msg, int status, t_pipex *pipex);
char	**get_paths(char **envp);
void	pipex_init(t_pipex *pipex);

#endif
