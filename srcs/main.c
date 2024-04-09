/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:53:50 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/09 18:01:43 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child1(t_pipex *ppx, char **argv)
{
	int	input;

	input = open(argv[1], O_RDONLY);
	if (input == -1)
	{
		handle_error(PATH, argv[1]);
		create_file(argv[4]);
		free_ppx(ppx);
		exit(127);
	}
	dup2(input, STDIN_FILENO);
	close(input);
	dup2(ppx->fd[1], STDOUT_FILENO);
	close(ppx->fd[1]);
	close(ppx->fd[0]);
	parse_cmd(ppx, argv[2], argv);
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
	dup2(ppx->fd[0], STDIN_FILENO);
	close(ppx->fd[0]);
	dup2(output, STDOUT_FILENO);
	close(output);
	close(ppx->fd[1]);
	parse_cmd(ppx, argv[3], argv);
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
	return(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		ppx;
	
	ppx = (t_pipex){0};
	if (argc != 5)
	{
		ft_putstr_fd(ARGC, 2);
		return(1);
	}
	check_input(argv);
	ppx.env = envp;
	pipex(&ppx, argv);
	return (0);
}
