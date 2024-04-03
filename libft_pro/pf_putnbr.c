/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:37:56 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/09 14:33:19 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putnbr(int num, int *check)
{
	int	count;

	count = 0;
	if (num == -2147483648)
		return (count += pf_putstr("-2147483648", check));
	if (num < 0)
	{
		count += pf_putchar('-', check);
		num *= -1;
	}
	while (num > 9)
	{
		count += pf_putnbr((num / 10), check);
		num = num % 10;
	}
	if (num >= 0 && num <= 9)
		count += pf_putchar((num + 48), check);
	return (count);
}
