/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student->hive->fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:11:06 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/04 17:29:18 by aneitenb         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipex *ppx, char **argv)
{
	int	input;

	input = open(argv[1], O_RDONLY);
	if (input == -1)
	{
		perror("pipex: ");
		exit(127);
	}
	parse_cmd(ppx, argv[2]);
	access_cmd(ppx);
	dup2(input, STDIN_FILENO);
	close(input);
	dup2(ppx->fd[1], STDOUT_FILENO);
	close(ppx->fd[1]);
	close(ppx->fd[0]);
	if (execve(ppx->chosen, ppx->cmd, ppx->env) == -1)
	{
		perror("pipex: ");
		free_ppx(ppx);
		exit(127);
	}
}

void	child2(t_pipex *ppx, char **argv)
{
	int	output;

	output = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	parse_cmd(ppx, argv[3]);
	access_cmd(ppx);
	dup2(ppx->fd[0], STDIN_FILENO);
	close(ppx->fd[0]);
	dup2(output, STDOUT_FILENO);
	close(output);
	close(ppx->fd[1]);
	if (execve(ppx->chosen, ppx->cmd, ppx->env) == -1)
	{
		perror("pipex: ");
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
	
	if (argc > 5)
	{
		ft_putstr_fd(ARGC, 2);
		return(1);
	}
	check_input(argv);
	// ft_memset(&ppx, 0, sizeof(t_pipex));	//don't need if using stack memory
	ppx.env = envp;
	pipex(&ppx, argv);
	return (0);
}