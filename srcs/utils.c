/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:19:01 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/09 18:01:13 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/pipex.h"

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
	int		i;
	
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

void	check_access(t_pipex *ppx)
{
	if (!access(ppx->chosen, F_OK))
	{
			if (!access(ppx->chosen, X_OK))
				return ;
			free_ppx(ppx);
			error_cmd_exit(CMD, ppx, ppx->cmd[0]);
	}
	else
	{
		if (!access(ppx->chosen, F_OK))
			error_cmd_exit(PERM2, ppx, ppx->cmd[0]);
		// free_ppx(ppx);	//this is creating memory problems with pointers being freed that aren't allocated
		error_cmd_exit(CMD, ppx, ppx->cmd[0]);
	}
}

void	access_cmd(t_pipex *ppx)
{
	int	i;
	
	i = 0;
	get_path(ppx);
	if (!access(ppx->cmd[0], F_OK))
		if (!access(ppx->cmd[0], X_OK))
		{
			ppx->chosen = ppx->cmd[0];
			return ;
		}
	while (ppx->paths[i])
	{
		ppx->chosen = ft_strsjoin(ppx->paths[i], ppx->cmd[0], '/');
		if (ppx->chosen == NULL)
			error_exit(SJOIN, ppx);
		if (!access(ppx->chosen, F_OK))
		{
			if (!access(ppx->chosen, X_OK))
				break ;
			// free_ppx(ppx); causes mem problems: freeing pointers that aren't allocated
			error_cmd_exit(CMD, ppx, ppx->cmd[0]);
		}
		i++;
	}
	check_access(ppx);
}

void	parse_cmd(t_pipex *ppx, char *arg, char **argv)
{
	int			i;
	// int 		j;
	// static char	*longpath;
	static char	**temp;
	
	i = 0;
	temp = argv;	//delete!!!
	// j = 0;
	// temp = ppx->env;
	// while (temp[j])
	// {
	// 	if (ft_strncmp(temp[j], "PWD=", 4) == 0)
	// 		longpath = temp[j] + 4;
	// 	j++;
	// }
	// longpath = ft_strsjoin(longpath, arg, '/');
	// if (execve(longpath, &arg, ppx->env))
	// {
	// 	create_file(argv[4]);
	// 	error_cmd_exit(CMD, ppx, arg);
	// }
	
	// if (!access(arg, F_OK))
	// 	if (!access(ppx->cmd[0], X_OK))
	// 		error_cmd_exit(CMD, ppx, arg);
	if (ft_strncmp(arg, "./", 2) == 0)
		i += 2;
	ppx->cmd = ft_split(arg + i, ' ');
	if (ppx->cmd == NULL)
		error_exit(SPLIT, ppx);	//do i need to free(ppx) ?
}
