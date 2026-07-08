/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:39:35 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/06/05 11:38:44 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**free_str(char	**str, size_t j);
static int	word_count(const char	*s, char c);

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	start;

	str = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		str[j++] = ft_substr(s, start, (i - start));
		if (!str[j - 1])
			return (free_str(str, j));
	}
	str[j] = NULL;
	return (str);
}

char	**free_str(char	**str, size_t j)
{
	while (j > 0)
	{
		j--;
		free(str[j]);
	}
	free(str);
	return (NULL);
}

static int	word_count(const char	*s, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}
