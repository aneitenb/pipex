/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:19:01 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/06 12:26:05 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_input(char **argv)
{
	if (argv[2][0] == '\0' && argv[3][0] == '\0')
	{
		ft_putstr_fd(PERM, 2);
		ft_putstr_fd(PERM, 2);
		exit(1);
	}
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		ft_putstr_fd(PERM, 2);
		exit(1);
	}
}

void	get_path(t_pipex *ppx)
{
	static char	*longpath;
	int		i;
	
	i = 0;
	while (ppx->env[i])
	{
		if (ft_strncmp(ppx->env[i], "PATH=", 5) == 0)
			longpath = ppx->env[i] + 5;
		i++;
	}
	if (longpath == 0)
		error_exit(PATH, ppx);
	ppx->paths = ft_split(longpath, ':');
	if (ppx->paths == NULL)
		error_exit(SPLIT, ppx);
}

void	access_cmd(t_pipex *ppx)
{
	int	i;
	
	i = 0;
	get_path(ppx);
	while (ppx->paths[i])
	{
		ppx->chosen = ft_strsjoin(ppx->paths[i], ppx->cmd[0], '/');
		if (ppx->chosen == NULL)
			error_exit(SJOIN, ppx);
		if (!access(ppx->chosen, F_OK))
		{
			if (!access(ppx->chosen, X_OK))
				break ;
			free_ppx(ppx);
			error_cmd_exit(CMD, ppx, ppx->cmd[0]);
		}
		i++;
	}
}

void	parse_cmd(t_pipex *ppx, char *arg)
{
	int		i;

	i = 0;
	if (ft_strncmp(arg, "./", 2) == 0)
		i += 2;
	ppx->cmd = ft_split(arg + i, ' ');
	if (ppx->cmd == NULL)
		error_exit(SPLIT, ppx);	//do i need to free(ppx) ?
}