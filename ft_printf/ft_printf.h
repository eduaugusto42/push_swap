/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:26:01 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/08 16:30:09 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Libft
# include "../libft/libft.h"
# include <stdarg.h>

// Functions
int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_pointer(void *p);
int	ft_print_dec(int i);
int	ft_print_unsigned(unsigned int u);
int	ft_print_hex(unsigned long x, char c);

#endif
