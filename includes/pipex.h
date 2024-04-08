/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:35:28 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/08 17:32:36 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

/* for close, read, write, unlink, dup, dup2, execve, fork, pipe, access */
# include <unistd.h>

/* for open */
# include <fcntl.h>

/* for strerror */
# include <string.h>

/* for malloc, free, exit */
# include <stdlib.h>

/* for perror */
# include <stdio.h>

/* for waitpid, wait, */
# include <sys/wait.h>

/* MACROS */
# define ARGC "pipex: incorrect input of arguments\n"
# define PERM "pipex: permission denied\n"
# define PERM2 "pipex: permission denied"
# define PIPE "pipex: could not create pipe\n"
# define CHILD "pipex: could not create child\n"
# define CMD "pipex: command not found: "
# define PATH "pipex: invalid path\n"
# define SPLIT "pipex: ft_split failure\n"
# define SJOIN "pipex: ft_strjoin failure\n"


typedef struct s_pipex
{
	char	**paths;
	char	**env;
	char	*chosen;
	char	**cmd;
	pid_t	pid[2];
	int		fd[2];
}	t_pipex;

void	error_exit(char *str, t_pipex *ppx);
void	error_cmd_exit(char *str, t_pipex *ppx, char *cmd);
void	handle_error(char *str);
void	free_ppx(t_pipex *ppx);
// void	ft_closefd(t_pipex *ppx);
void	check_input(char **argv);
void	access_cmd(t_pipex *ppx);
void	parse_cmd(t_pipex *ppx, char *arg);
void	get_path(t_pipex *ppx);

#endif 
