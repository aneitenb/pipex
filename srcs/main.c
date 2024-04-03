/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:11:06 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/03 20:06:27 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"



//int ft_exec(char **)


//int ft_handlechild
/*
dup2(stdout, pipe[1])
*/

//int ft_handleparent()
/**
 dup2(pipe[0], STDIN)
 * 
*/
//int ft_fork()
/**
 * 
 * parse_cmds()
 * check access()
 * fork()
*/


int	main(int argc, char **argv, char **envp)
{
	t_pipex		ppx;

	if (argc > 5)
		error_message(ARGC);
	check_input(argv);
	// ft_memset(&ppx, 0, sizeof(t_pipex));
	ppx.env = envp;
	pipex(ppx, argv);
	return (0);
}
