/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:11:06 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/03 19:49:36 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
void	child_op1(t_pipex ppx, char **argv)
{
	int	input;

	input = open(argv[1], O_RDONLY);
	if (input == -1)
	{
		perror("pipex");
		close(input);
		exit(127);
	}
	parse_cmd(ppx, argv[2]);
	access_cmd(ppx);
	dup2(input, STDIN_FILENO);
	close(input);
	dup2(ppx.fd[1], STDOUT_FILENO);
	close(ppx.fd[1]);
	close(ppx.fd[0]);
	if (execve(ppx.chosen, ppx.cmd, ppx.env) == -1)
	{
		perror("pipex: FILL IN");
		free_array(ppx);
		free(ppx.chosen);
		exit(1);
	}
}

// void	child_op2(t_pipex ppx, char **argv)
// {
// 	int	output;

// 	output = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	parse_cmd(ppx, argv[3]);
// 	access_cmd(ppx);
// 	dup2(ppx.fd[0], STDIN_FILENO);
// 	close(ppx.fd[0]);
// 	dup2(output, STDOUT_FILENO);
// 	close(output);
// 	close(ppx.fd[1]);
// 	printf("hello");
// 	fflush(stdout);
// 	if (execve(ppx.chosen, ppx.cmd, ppx.env) == -1)
// 	{
// 		perror("pipex: FILL IN");
// 		free_array(ppx);
// 		free(ppx.chosen);
// 		exit(1);
// 	}
// }

void	pipex(t_pipex ppx, char **argv)
{
	if (pipe(ppx.fd) == -1)
		error_exit(PIPE, ppx);
	ppx.pid[0] = fork();
	if (ppx.pid[0] < 0)
		error_exit(CHILD, ppx);
	if (ppx.pid[0] == 0)
		child_op1(ppx, argv);
	// ppx.pid[1] = fork();
	// if (ppx.pid[1] < 0)
	// {
	// 	error_exit(CHILD, ppx); 
	// 	waitpid(ppx.pid[0], 0, 0);
	// }
	// if (ppx.pid[1] == 0)
	// 	child_op2(ppx, argv);
	close(ppx.fd[0]);
	close(ppx.fd[1]);
}
*/


int	main(int argc, char **argv, char **envp)
{
	t_pipex		ppx;
	
	if (argc > 5)
		error_message(ARGC);
	check_input(argv);
	// ft_memset(&ppx, 0, sizeof(t_pipex));
	ppx.env = envp;
	pipex(ppx, argv);
	return (0);
}
