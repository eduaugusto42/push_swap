/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 09:13:10 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/31 11:34:10 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last;
	unsigned char	uc;

	last = NULL;
	uc = c;
	while (1)
	{
		if (*s == uc)
			last = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (last);
}
