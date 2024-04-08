/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:20:01 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/08 18:06:00 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_exit(char *str, t_pipex *ppx)
{
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	error_cmd_exit(char *str, t_pipex *ppx, char *cmd)
{
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2); 
	exit(1);
}

void	handle_error(char *str)
{
	ft_putstr_fd(PERM2, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

void	free_ppx(t_pipex *ppx)	
{
	if (ppx->paths)
	{
		while(ppx->paths)
		{
			free(ppx->paths);
			ppx->paths++;
		}
		free (ppx->paths);
	}
	// if (ppx->env)		//don't need this since I'm not allocating memory on the heap
	// {
	// 	while(ppx->env)
	// 	{
	// 		free(ppx->env);
	// 		ppx->env++;
	// 	}
	// 	free (ppx->env);
	// }
	if (ppx->chosen)
		free(ppx->chosen);
	if (ppx->cmd) 
	{
		while(ppx->cmd)
		{
			free(ppx->cmd);
			ppx->cmd++;
		}
		free (ppx->cmd);
	}
	// free(ppx);
}
