/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:46:10 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/06/17 11:01:07 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	char	*null_str;

	null_str = "(null)";
	if (s == NULL)
	{
		ft_putstr_fd(null_str, 1);
		return (ft_strlen(null_str));
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
