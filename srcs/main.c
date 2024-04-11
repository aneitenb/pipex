/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:53:50 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/11 18:54:24 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_ppx(t_pipex *ppx)
{
	ppx->paths = 0;
	ppx->chosen = 0;
	ppx->cmd = 0;
	ppx->i = 0;
	ppx->j = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		ppx;

	ppx = (t_pipex){0};
	if (argc != 5)
	{
		ft_putstr_fd(ARGC, 2);
		return (1);
	}
	init_ppx(&ppx);
	check_input(argv);
	ppx.env = envp;
	return (pipex(&ppx, argv));
}
