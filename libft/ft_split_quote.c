/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:18:38 by aneitenb          #+#    #+#             */
/*   Updated: 2024/04/12 16:55:38 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while ((i < len) && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

void	word_count(char *str, t_split *sp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			sp->wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			if (str[i] == 39)
			{
				i++;
				while (str[i] && str[i] != 39)
					i++;
			}
			if (str[i] == 39)
			{
				i++;
				break ;
			}
			i++;
		}
	}
}

char	**init_sp(t_split *sp, char *str)
{
	sp->i = 0;
	sp->j = 0;
	sp->k = 0;
	sp->wc = 0;
	word_count(str, sp);
	sp->array = (char **)malloc(sizeof(char *) * (sp->wc + 1));
	if (sp->array == NULL)
		return (NULL);
	return (sp->array);
}

void	scan_str(char **str)
{
	while (**str)
	{
		if ((**str == ' ' || **str == '\t' || **str == '\n'))
			**str = 31;
		if (**str == 39 || **str == 34 || **str == '{' || **str == '}')
		{
			if (**str == 39 || **str == 34)
			{
				**str = 31;
				(*str)++;
			}
			if (**str == '{' || **str == '}')
				(*str)++;
			while (**str && (**str != 39 && **str != 34
					&& **str != '{' && **str != '}'))
				(*str)++;
			if (**str == '{' || **str == '}')
				(*str)++;
			if (**str == 39 || **str == 34)
				**str = 31;
		}
		if ((*str + 1))
			(*str)++;
	}
}

char	**ft_split_quote(char *str)
{
	t_split	sp;
	char	*ptr;

	ptr = str;
	if (init_sp(&sp, str) == NULL)
		return (NULL);
	scan_str(&str);
	while (ptr[sp.i])
	{
		while (ptr[sp.i] && (ptr[sp.i] == 31))
			sp.i++;
		sp.j = sp.i;
		while (ptr[sp.i] && (ptr[sp.i] != 31))
			sp.i++;
		if (sp.i > sp.j)
		{
			sp.array[sp.k] = (char *)malloc(sizeof(char) * ((sp.i - sp.j) + 1));
			if (sp.array[sp.k] == NULL)
				return (NULL);
			ft_strncpy(sp.array[sp.k], &ptr[sp.j], sp.i - sp.j);
			sp.k++;
		}
	}
	sp.array[sp.k] = NULL;
	return (sp.array);
}
