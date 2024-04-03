/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:37:45 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/09 14:33:27 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putstr(char *str, int *check)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (pf_putstr("(null)", check));
	while (str[i])
	{
		count += pf_putchar(str[i], check);
		i++;
	}
	return (count);
}
