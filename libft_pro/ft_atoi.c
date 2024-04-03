/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:16:10 by aneitenb          #+#    #+#             */
/*   Updated: 2023/11/20 13:53:35 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_finish(const char *str, int i, long res, int sign)
{
	long	previous;

	while (str[i] >= '0' && str[i] <= '9')
	{
		previous = res;
		res = res * 10 + str[i] - '0';
		i++;
		if (res < previous || (res % 100) / 10 != previous % 10)
		{
			if (sign == 1)
				return (-1);
			else if (sign == -1)
				return (0);
		}
	}
	return ((int)res * sign);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (ft_finish(str, i, res, sign));
}
