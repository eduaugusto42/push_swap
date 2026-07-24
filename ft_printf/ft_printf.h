/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:26:01 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/23 17:41:29 by jcesar-o         ###   ########.fr       */
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
