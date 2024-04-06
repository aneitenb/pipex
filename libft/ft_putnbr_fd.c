/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:48:18 by aneitenb          #+#    #+#             */
/*   Updated: 2023/11/15 14:37:13 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	new;

	if (n < 0)
	{
		new = (unsigned int)(n * -1);
		ft_putchar_fd('-', fd);
	}
	else
		new = (unsigned int)n;
	if (new > 9)
	{
		ft_putnbr_fd(new / 10, fd);
		new = new % 10;
	}
	if (new >= 0 && new <= 9)
		ft_putchar_fd((new + 48), fd);
}
