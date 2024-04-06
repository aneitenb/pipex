/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:46:49 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/05 16:22:27 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsjoin(char const *s1, char const *s2, char sep)
{
	char	*new;
	size_t	newlen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	newlen = ft_strlen(s1) + ft_strlen(s2) + 2;
	new = malloc(newlen);
	if (new == NULL)
		return (NULL);
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	if (sep)
		new[j++] = sep;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}
