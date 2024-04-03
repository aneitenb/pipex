/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:35:28 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/03 20:04:17 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft_pro/libft.h"

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
# define ARGC "pipex: Incorrect input of arguments\n"
# define PIPE "pipex: Could not create pipe\n"
# define CHILD "pipex: Could not create child\n"
# define CMD "pipex: Command invalid\n"

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
void	error_message(char *str);
void	check_input(char **argv);
void	get_path(char **envp, t_pipex ppx);
void	access_cmd(t_pipex *ppx);
void	parse_cmd(t_pipex *ppx, char *arg);
void	free_array(t_pipex *ppx);

#endif 
