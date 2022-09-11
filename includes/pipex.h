/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:45 by test              #+#    #+#             */
/*   Updated: 2022/09/12 01:53:19 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"

typedef struct s_pipex
{
	int outfile;
	int infile;
	char *cmd_file;
	char **cmd;
}	t_pipex;
// int pipex(int argc, char **argv, char **envp);
