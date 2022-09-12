/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:36:24 by test              #+#    #+#             */
/*   Updated: 2022/09/12 15:57:27 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp) {
	t_pipex pipex_info;
	
	ft_split(NULL, ':');
	if (argc != 5)
		error_exit("no");
	if (!envp)
		error_exit("NO");
	pipex_info.infile = open(argv[1], O_RDONLY | O_CLOEXEC);
	if (!pipex_info.infile)
		error_exit("Could not open file");
	pipex_info.outfile = open(argv[argc - 1], \
	(O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC), 0644);
	if (!pipex_info.outfile)
		error_exit("Could not open file");
	pipex(pipex_info, argv, envp);
	return (0);
}
