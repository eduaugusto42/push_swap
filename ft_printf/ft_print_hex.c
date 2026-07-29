/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:47:59 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/29 18:17:03 by jcesar-o         ###   ########.fr       */
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
	ft_putchar_fd(hex[x % 16], 2);
	return (len);
}
