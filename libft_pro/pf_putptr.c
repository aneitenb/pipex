/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:57:28 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/09 14:33:23 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putptr(void *ptr, int *check)
{
	int	count;

	count = 0;
	count += pf_putstr("0x", check);
	count += pf_puthexbase((unsigned long)ptr, 0, check);
	return (count);
}
