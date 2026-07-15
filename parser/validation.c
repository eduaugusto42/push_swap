/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:39:58 by juliopestan       #+#    #+#             */
/*   Updated: 2026/07/14 19:06:21 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	is_valid_number(char *token)
{
	int	i;

	i = 0;
	if (!token || token[i] == '\0')
		return (0);
	if (token[i] == '-' || token[i] == '+')
		i++;
	if (token[i] == '\0')
		return (0);
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int_range(char *token)
{
	long	nbr;

	nbr = ft_atol(token);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_token(char *token, int *value)
{
	if (!is_valid_number(token))
		return (0);
	if (!is_int_range(token))
		return (0);
	*value = (int)ft_atol(token);
	return (1);
}
