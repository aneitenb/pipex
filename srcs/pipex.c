/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:31:58 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/12 14:52:37 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	create_file(char *arg)
{
	int	temp;

	temp = open(arg, O_CREAT, 0644);
	close(temp);
}

void	child1(t_pipex *ppx, char **argv)
{
	int	input;

	input = open(argv[1], O_RDONLY);
	if (input < 0)
	{
		handle_in_error(argv[1]);
		create_file(argv[4]);
		free_ppx(ppx);
		exit(127);
	}
	dup2(input, STDIN_FILENO);
	close(input);
	dup2(ppx->fd[1], STDOUT_FILENO);
	close(ppx->fd[1]);
	close(ppx->fd[0]);
	parse_cmd(ppx, argv[2]);
	access_cmd(ppx);
	if (execve(ppx->chosen, ppx->cmd, ppx->env) == -1)
	{
		handle_error(PERM2, ppx->cmd[0]);
		create_file(argv[4]);
		free_ppx(ppx);
		exit(127);
	}
}

void	child2(t_pipex *ppx, char **argv)
{
	int	output;

	output = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (output < 0)
	{
		handle_in_error(argv[4]);
		create_file(argv[4]);
		free_ppx(ppx);
		exit(127);
	}
	dup2(ppx->fd[0], STDIN_FILENO);
	close(ppx->fd[0]);
	dup2(output, STDOUT_FILENO);
	close(output);
	close(ppx->fd[1]);
	parse_cmd(ppx, argv[3]);
	access_cmd(ppx);
	if (execve(ppx->chosen, ppx->cmd, ppx->env) == -1)
	{
		handle_error(PERM2, ppx->cmd[0]);
		create_file(argv[4]);
		free_ppx(ppx);
		exit(127);
	}
}

int	pipex(t_pipex *ppx, char **argv)
{
	int	status;

	if (pipe(ppx->fd) == -1)
		error_exit(PIPE, ppx);
	ppx->pid[0] = fork();
	if (ppx->pid[0] < 0)
		error_exit(CHILD, ppx);
	if (ppx->pid[0] == 0)
		child1(ppx, argv);
	ppx->pid[1] = fork();
	if (ppx->pid[1] < 0)
		error_exit(CHILD, ppx);
	if (ppx->pid[1] == 0)
		child2(ppx, argv);
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	waitpid(ppx->pid[0], &status, 0);
	waitpid(ppx->pid[1], &status, 0);
	free_ppx(ppx);
	return (WEXITSTATUS(status));
}
