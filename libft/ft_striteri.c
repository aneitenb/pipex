/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:52:30 by aneitenb          #+#    #+#             */
/*   Updated: 2023/11/15 14:38:45 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))

{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
