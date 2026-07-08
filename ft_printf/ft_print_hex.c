/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:47:59 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/06/17 17:09:05 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long x, char c)
{
	const char	*hex;
	int			len;

	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	len = 1;
	if (x / 16 != 0)
		len += ft_print_hex(x / 16, c);
	ft_putchar_fd(hex[x % 16], 1);
	return (len);
}
