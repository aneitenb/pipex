/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:02:25 by aneitenb          #+#    #+#             */
/*   Updated: 2023/11/15 14:41:49 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substring;

	if (!s)
		return (NULL);
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	i = 0;
	j = 0;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			substring[j++] = s[i];
		i++;
	}
	substring[j] = '\0';
	return (substring);
}
