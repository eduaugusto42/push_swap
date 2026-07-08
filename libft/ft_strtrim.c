/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 09:52:26 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/06/10 13:00:27 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const	c, char	const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && is_set(s1[i], set) == 1)
		i++;
	if (i == j)
		return (ft_strdup(""));
	j--;
	while (j > i && is_set(s1[j], set) == 1)
		j--;
	len = (j - i) + 1;
	s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	len = 0;
	while (i <= j)
		s2[len++] = s1[i++];
	s2[len] = '\0';
	return (s2);
}

static int	is_set(char const	c, char	const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
