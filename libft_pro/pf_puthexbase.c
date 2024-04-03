/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthexbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:13:54 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/09 14:33:14 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_puthexbase(unsigned long num, int cap, int *check)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += pf_puthexbase((num / 16), cap, check);
		count += pf_puthexbase((num % 16), cap, check);
	}
	if (cap == 0 && (num >= 10 && num <= 15))
		count += pf_putchar((num + 87), check);
	if (cap == 1 && (num >= 10 && num <= 15))
		count += pf_putchar((num + 55), check);
	if (num <= 9)
		count += pf_putnbr(num, check);
	return (count);
}
