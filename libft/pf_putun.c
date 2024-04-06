/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:42:32 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/09 14:33:32 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putun(unsigned int num, int *check)
{
	int	count;

	count = 0;
	while (num > 9)
	{
		count += pf_putnbr((num / 10), check);
		num = num % 10;
	}
	if (num >= 0 && num <= 9)
		count += pf_putchar((num + 48), check);
	return (count);
}
