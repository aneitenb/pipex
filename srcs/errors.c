/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:20:01 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/11 18:55:56 by aneitenb         ###   ########.fr       */
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

void	handle_error(char *msg, char *str)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

void	handle_in_error(char *arg)
{
	if (!access(arg, F_OK))
	{
		ft_putstr_fd(PERM2, 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd(PATH, 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\n", 2);
	}
}

void	free_ppx(t_pipex *ppx)
{
	if (ppx->paths)
	{
		ppx->j = 0;
		while (ppx->paths)
		{
			if (ppx->paths[ppx->j] != NULL)
				free(ppx->paths[ppx->j]);
			ppx->j++;
		}
		free (ppx->paths);
	}
	if (ppx->cmd)
	{
		ppx->j = 0;
		while (ppx->cmd)
		{
			if (ppx->cmd[ppx->j] != NULL)
				free(ppx->cmd[ppx->j]);
			ppx->j++;
		}
		free (ppx->cmd);
	}
	if (ppx->chosen)
		free(ppx->chosen);
}
