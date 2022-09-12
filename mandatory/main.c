/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:36:24 by test              #+#    #+#             */
/*   Updated: 2022/09/13 01:03:50 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex_info;

	pipex_init(&pipex_info);
	if (argc != 5)
		error_exit("Bad arguments", EX_USAGE, &pipex_info);
	if (!envp)
		error_exit("envp is NULL", EXIT_FAILURE, &pipex_info);
	pipex_info.infile = open(argv[1], O_RDONLY | O_CLOEXEC);
	if (pipex_info.infile == -1)
		perror_exit("Infile", EXIT_FAILURE, &pipex_info);
	pipex_info.outfile = open(argv[argc - 1], \
	(O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC), 0644);
	if (pipex_info.outfile == -1)
		perror_exit("Outfile", EXIT_FAILURE, &pipex_info);
	pipex(pipex_info, argv, envp);
	return (0);
}
