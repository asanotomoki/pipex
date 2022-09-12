/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:56:59 by test              #+#    #+#             */
/*   Updated: 2022/09/12 16:10:08 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error_exit(const char *msg) {
	perror(msg);
	exit(1);
}

char **get_path(char **envp) {
	char **path;
	while(ft_strncmp(*envp,"PATH", 4) != 0)
		envp++;
	if (!*envp)
		error_exit("no");
	*envp += 5;
	path = ft_split(*envp, ':');
	if (!path)
		error_exit("malloc");
	return (path);
}

char *get_cmdfile(char **paths, char *cmd) {
	char *tmp;
	char *cmd_paths;
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd_paths = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_paths, X_OK) == 0)
			return (cmd_paths);
		free(cmd_paths);
		paths++;
	}
	return (NULL);
}

void parent_process(t_pipex pipex, char *cmd, char **envp) {
		//stdinと繋げる
	close(pipex.pipefd[1]);
	dup2(pipex.pipefd[0], 0);
	close(pipex.pipefd[0]);
	dup2(pipex.outfile, 1);
	//コマンドの実行
	pipex.cmds = ft_split(cmd, ' ');
	if (!pipex.cmds)
	{
		error_exit("split");
	}
	pipex.cmd_file = get_cmdfile(pipex.cmd_paths, pipex.cmds[0]);
	if (!pipex.cmd_file)
	{
		error_exit("no file");
	}
	execve(pipex.cmd_file, pipex.cmds, envp);
}

void child_process(t_pipex pipex, char *cmd, char **envp) {
	//stdinと繋げる
	if (close(pipex.pipefd[0]))
		error_exit("could not close");
	if(dup2(pipex.pipefd[1], 1))
		error_exit("dup2");
	close(pipex.pipefd[1]);
	dup2(pipex.infile, 0);
	//コマンドの実行
	pipex.cmds = ft_split(cmd, ' ');
	if (!pipex.cmds)
	{
		error_exit("split");
	}
	pipex.cmd_file = get_cmdfile(pipex.cmd_paths, pipex.cmds[0]);
	if (!pipex.cmd_file)
	{
		error_exit("no file");
	}
	execve(pipex.cmd_file, pipex.cmds, envp);
}

int pipex(t_pipex pipex, char **argv, char **envp)
{
	pid_t	pid;
	int *status;

	pipex.cmd_paths = get_path(envp);
	if (pipe(pipex.pipefd) == -1)
		error_exit("pipe");
	pid = fork();
	if (pid > 0)
	{
		if (waitpid(pid, status, 0) < 0)
			error_exit("child process");
		parent_process(pipex, argv[3], envp);
	}
	else if (pid == 0)
		child_process(pipex, argv[2], envp);
	else
		error_exit("pid");
	return (0);
}
