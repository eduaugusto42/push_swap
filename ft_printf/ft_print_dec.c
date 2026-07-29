/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:47:59 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/29 18:16:56 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(int i)
{
	char	*itoa;
	int		len;

	itoa = ft_itoa(i);
	ft_putstr_fd(itoa, 2);
	len = ft_strlen(itoa);
	free(itoa);
	return (len);
}
