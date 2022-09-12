/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:56:59 by test              #+#    #+#             */
/*   Updated: 2022/09/13 01:56:41 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
{
	char	**paths;

	while (*envp && (ft_strncmp(*envp, "PATH=", 5) != 0))
		envp++;
	if (!*envp)
		return (NULL);
	*envp += 5;
	paths = ft_split(*envp, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char	*get_cmdfile(char **paths, char *cmd)
{
	char	*tmp;
	char	*cmd_path;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		paths++;
	}
	return (NULL);
}

void	parent_process(t_pipex pipex, char *cmd, char **envp)
{
	close(pipex.pipefd[1]);
	if (dup2(pipex.pipefd[0], STDIN_FILENO) == -1)
		perror_exit("Parent dup2", EXIT_FAILURE, &pipex);
	close(pipex.pipefd[0]);
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
		perror_exit("Parent dup2", EXIT_FAILURE, &pipex);
	pipex.cmds = ft_split(cmd, ' ');
	if (!pipex.cmds)
		perror_exit("Parent cmds", EXIT_FAILURE, &pipex);
	pipex.cmd_file = get_cmdfile(pipex.cmd_paths, pipex.cmds[0]);
	if (!pipex.cmd_file)
		error_exit(ERR_PAR_CMD, EXIT_FAILURE, &pipex);
	free_args(&pipex.cmd_paths);
	if (execve(pipex.cmd_file, pipex.cmds, envp) == -1)
		perror_exit("Parent execve", EXIT_FAILURE, &pipex);
}

void	child_process(t_pipex pipex, char *cmd, char **envp)
{
	close(pipex.pipefd[0]);
	if (dup2(pipex.pipefd[1], STDOUT_FILENO) == -1)
		perror_exit("Child dup2", EXIT_FAILURE, &pipex);
	close(pipex.pipefd[1]);
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		perror_exit("Child dup2", EXIT_FAILURE, &pipex);
	pipex.cmds = ft_split(cmd, ' ');
	if (!pipex.cmds)
		perror_exit("Child cmds", EXIT_FAILURE, &pipex);
	pipex.cmd_file = get_cmdfile(pipex.cmd_paths, pipex.cmds[0]);
	if (!pipex.cmd_file)
		error_exit(ERR_CHI_CMD, EXIT_FAILURE, &pipex);
	free_args(&pipex.cmd_paths);
	if (execve(pipex.cmd_file, pipex.cmds, envp) == -1)
		perror_exit("Child execve", EXIT_FAILURE, &pipex);
}

int	pipex(t_pipex pipex, char **argv, char **envp)
{
	pid_t	pid;

	pipex.cmd_paths = get_paths(envp);
	if (!pipex.cmd_paths)
		error_exit(ERR_CMD_PATH, EXIT_FAILURE, &pipex);
	if (pipe(pipex.pipefd) == -1)
		perror_exit("pipe", EXIT_FAILURE, &pipex);
	pid = fork();
	if (pid > 0)
	{
		if (waitpid(pid, NULL, 0) == -1)
			perror_exit("waitpid", EXIT_FAILURE, &pipex);
		parent_process(pipex, argv[3], envp);
	}
	else if (pid == 0)
		child_process(pipex, argv[2], envp);
	else
		perror_exit("pid", EXIT_FAILURE, &pipex);
	return (0);
}
