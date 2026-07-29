/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:46:10 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/29 18:17:29 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	char	*null_str;

	null_str = "(null)";
	if (s == NULL)
	{
		ft_putstr_fd(null_str, 2);
		return (ft_strlen(null_str));
	}
	ft_putstr_fd(s, 2);
	return (ft_strlen(s));
}
