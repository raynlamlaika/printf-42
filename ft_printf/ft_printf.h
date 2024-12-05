/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:52:38 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/03 22:45:42 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

char	*ft_strchr(const char *str, int c);
int		putchar(int c);
int		ft_printf(const char *forma, ...);
int		putstr(char *string);
int		putnbr(int n);
int		hexa(unsigned long nbr, char *base);
int		putpointer(void *ptr);
int		putunsigned(unsigned int n);

#endif