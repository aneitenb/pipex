/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:00:44 by aneitenb          #+#    #+#             */
/*   Updated: 2023/11/20 13:59:41 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	newlen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	newlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(newlen);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, newlen);
	ft_strlcat(new, s2, newlen);
	return (new);
}
