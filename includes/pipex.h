/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:45 by test              #+#    #+#             */
/*   Updated: 2022/09/12 15:41:49 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"

typedef struct s_pipex
{
	int pipefd[2];
	int outfile;
	int infile;
	char **cmd_paths;
	char *cmd_file;
	char **cmds;
}	t_pipex;

int pipex(t_pipex pipex, char **argv, char **envp);
void error_exit(const char *msg);
