/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:19:01 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/11 18:56:21 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_input(char **argv)
{
	if (argv[2][0] == '\0' && argv[3][0] == '\0')
	{
		create_file(argv[4]);
		ft_putstr_fd(PERM, 2);
		ft_putstr_fd(PERM, 2);
		exit(1);
	}
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		create_file(argv[4]);
		ft_putstr_fd(PERM, 2);
		exit(1);
	}
}

void	get_path(t_pipex *ppx)
{
	static char	*longpath;
	int			i;

	i = 0;
	while (ppx->env[i])
	{
		if (ft_strncmp(ppx->env[i], "PATH=", 5) == 0)
			longpath = ppx->env[i] + 5;
		i++;
	}
	if (longpath == 0)
		error_cmd_exit(PATH, ppx, ppx->cmd[0]);
	ppx->paths = ft_split(longpath, ':');
	if (ppx->paths == NULL)
		error_exit(SPLIT, ppx);
}

void	check_access(t_pipex *ppx, int flag)
{
	if (flag == 1)
	{
		if (!access(ppx->cmd[0], F_OK))
		{
			if (!access(ppx->cmd[0], X_OK))
				return ;
			error_cmd_exit(PERM2, ppx, ppx->cmd[0]);
		}
	}
	if (!access(ppx->chosen, F_OK))
	{
		if (!access(ppx->chosen, X_OK))
			return ;
		error_cmd_exit(CMD, ppx, ppx->cmd[0]);
	}
	else
	{
		if (!access(ppx->chosen, F_OK))
			error_cmd_exit(PERM2, ppx, ppx->cmd[0]);
		error_cmd_exit(CMD, ppx, ppx->cmd[0]);
	}
}

void	access_cmd(t_pipex *ppx)
{
	ppx->i = 0;
	get_path(ppx);
	if (!access(ppx->cmd[0], F_OK))
	{
		if (!access(ppx->cmd[0], X_OK))
		{
			ppx->chosen = ppx->cmd[0];
			return ;
		}
	}
	while (ppx->paths[ppx->i])
	{
		ppx->chosen = ft_strsjoin(ppx->paths[ppx->i], ppx->cmd[0], '/');
		if (ppx->chosen == NULL)
			error_exit(SJOIN, ppx);
		if (!access(ppx->chosen, F_OK))
		{
			if (!access(ppx->chosen, X_OK))
				break ;
			error_cmd_exit(CMD, ppx, ppx->cmd[0]);
		}
		ppx->i++;
	}
	check_access(ppx, 0);
}

void	parse_cmd(t_pipex *ppx, char *arg)
{
	if (ft_strncmp(arg, "/", 1) == 0)
	{
		ppx->cmd = ft_split(arg, ' ');
		if (ppx->cmd == NULL)
			error_exit(SPLIT, ppx);
	}
	else if (ft_strncmp(arg, "./", 2) == 0)
	{
		ppx->cmd = ft_split(arg, ' ');
		if (ppx->cmd == NULL)
			error_exit(SPLIT, ppx);
		check_access(ppx, 1);
		ppx->cmd = ft_split(arg + 2, ' ');
		if (ppx->cmd == NULL)
			error_exit(SPLIT, ppx);
	}
	else
	{
		ppx->cmd = ft_split_quote(arg);
		if (ppx->cmd == NULL)
			error_exit(SPLIT, ppx);
		if (!access(ppx->cmd[0], F_OK))
			if (!access(ppx->cmd[0], X_OK))
				error_cmd_exit(CMD, ppx, arg);
	}
}
