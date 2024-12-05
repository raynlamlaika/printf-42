/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:54:37 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/05 21:38:23 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier(const char *forma, va_list count)
{
	int	lenght;

	lenght = 0;
	if (*forma == 'u')
		lenght += putunsigned(va_arg(count, unsigned int));
	if (*forma == '%')
		lenght += write(1, forma, 1);
	if (*forma == 'c')
		lenght += putchar(va_arg(count, int));
	if (*forma == 's')
		lenght += putstr(va_arg(count, char *));
	if (*forma == 'p')
		lenght += putpointer(va_arg(count, void *));
	if (*forma == 'd' || *forma == 'i')
		lenght += putnbr(va_arg(count, int));
	if (*forma == 'x')
		lenght += hexa(va_arg(count, unsigned int), "0123456789abcdef");
	if (*forma == 'X')
		lenght += hexa(va_arg(count, unsigned int), "0123456789ABCDEF");
	if (!(ft_strchr("cspdiuxX%%",*forma)))
		lenght += write(1, forma, 1);
	return (lenght);
}

int	ft_printf(const char *forma, ...)
{
	va_list	count;
	int		len;

	len = 0;
	va_start(count, forma);
	if (write(1, 0, 0) == -1)
		return (-1);
	while (*forma != '\0')
	{
		if (*forma == '%')
		{
			if (*(++forma) == '%')
				len += write(1, "%", 1);
			else if (*forma == '\0')
				break ;
			else
				len += specifier(forma, count);
		}
		else
			len += write(1, forma, 1);
		forma++;
	}
	va_end(count);
	return (len);
}
