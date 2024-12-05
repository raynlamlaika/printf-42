/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:50:52 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/03 20:05:41 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr(char *string)
{
	int	i;

	i = 0;
	if (!string)
		i += write(1, "(null)", 6);
	else
	{
		while (*string)
		{
			i += putchar(*string);
			string++;
		}
	}
	return (i);
}

int	putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += putstr("-2147483648");
		return (i);
	}
	else if (n < 0)
	{
		n = -n;
		i += write(1, "-", 1);
		i += putnbr(n);
	}
	else if (n > 9)
	{
		i += putnbr(n / 10);
		i += putnbr(n % 10);
	}
	else if (n <= 9 && n >= 0)
		i += putchar(n + '0');
	return (i);
}

int	hexa(unsigned long nbr, char *base)
{
	unsigned long	lenbase;
	int				i;

	lenbase = 16;
	i = 0;
	if (nbr >= lenbase)
	{
		i += hexa(nbr / lenbase, base);
		i += hexa(nbr % lenbase, base);
	}
	else
		i += putchar(base[nbr]);
	return (i);
}

int	putpointer(void *ptr)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	i += hexa((unsigned long)ptr, "0123456789abcdef");
	return (i);
}
