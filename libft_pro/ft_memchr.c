/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:10:37 by aneitenb          #+#    #+#             */
/*   Updated: 2023/11/15 14:35:21 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*str;

	i = 0;
	d = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == d)
			return (&str[i]);
		i++;
	}
	return (0);
}
