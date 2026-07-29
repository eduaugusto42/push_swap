/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:47:59 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/29 18:17:39 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int i)
{
	char	c;
	int		len;

	len = 1;
	if (i / 10 != 0)
		len += ft_print_unsigned(i / 10);
	c = '0' + (i % 10);
	ft_putchar_fd(c, 2);
	return (len);
}
