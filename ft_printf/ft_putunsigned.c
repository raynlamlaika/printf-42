/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:41:31 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/03 20:05:40 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += putunsigned(n / 10);
		i += putunsigned(n % 10);
	}
	else if (n <= 9 && n >= 0)
		i += putchar(n + '0');
	return (i);
}
