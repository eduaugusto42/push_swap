/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:47:59 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/29 18:19:00 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *p)
{
	int	len;

	if (!p)
	{
		ft_putstr_fd("(nil)", 2);
		return (5);
	}
	ft_putstr_fd("0x", 2);
	len = ft_print_hex((unsigned long)p, 'x') + 2;
	return (len);
}
