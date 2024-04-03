/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:04:41 by aneitenb          #+#    #+#             */
/*   Updated: 2023/11/20 13:59:36 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;
	size_t	buffer;
	size_t	append;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	buffer = dlen;
	append = dstsize - dlen - 1;
	if (dstsize <= dlen)
		return (dstsize + slen);
	while (i < append && src[i] != '\0')
	{
		dst[buffer] = src[i];
		buffer++;
		i++;
	}
	dst[buffer] = '\0';
	return (dlen + slen);
}
