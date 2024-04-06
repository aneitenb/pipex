/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:19:31 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/09 14:41:11 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_arguments(const char *format, va_list args, int *check)
{
	if (*format == 'c')
		return (pf_putchar(va_arg(args, int), check));
	else if (*format == 's')
		return (pf_putstr(va_arg(args, char *), check));
	else if (*format == 'p')
		return (pf_putptr(va_arg(args, void *), check));
	else if (*format == 'u')
		return (pf_putun(va_arg(args, unsigned int), check));
	else if (*format == 'd')
		return (pf_putnbr(va_arg(args, int), check));
	else if (*format == 'i')
		return (pf_putnbr(va_arg(args, int), check));
	else if (*format == 'x')
		return (pf_puthexbase(va_arg(args, unsigned int), 0, check));
	else if (*format == 'X')
		return (pf_puthexbase(va_arg(args, unsigned int), 1, check));
	else
		return (pf_putchar(*format, check));
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		check;
	va_list	args;

	count = 0;
	check = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += print_arguments(format, args, &check);
		}
		else
			count += pf_putchar(*format, &check);
		format++;
		if (check == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (count);
}
