/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:36:24 by test              #+#    #+#             */
/*   Updated: 2022/09/12 01:53:03 by test             ###   ########.fr       */
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

char *get_cmd(char **path, char *cmd) {
	char *tmp;
	char *cmd_path;
	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		path++;
	}
	return (NULL);
}

// void free_all(char **) {
	
// }

int main(int argc, char **argv, char **envp) {
	t_pipex pipex;
	
	if (argc != 5 || !envp)
		error_exit("no");
	pipex.cmd_file = get_cmd(get_path(envp), argv[2]);
	if (pipex.cmd_file)
		error_exit("no");
	printf("%s", pipex.cmd_file);
	return (0);
}
