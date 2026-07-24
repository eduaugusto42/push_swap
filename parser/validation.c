/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:39:58 by juliopestan       #+#    #+#             */
/*   Updated: 2026/07/24 17:46:56 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	convert_to_int(char *token, int *value)
{
	long	number;

	if (!is_valid_number(token))
		return (0);
	number = ft_atol(token);
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	*value = (int)number;
	return (1);
}

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

int	*has_duplicates(t_input *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < input->size)
	{
		j = i + 1;
		while (j < input->size)
		{
			if (input->numbers[i] == input->numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

double	compute_disorder(t_input *input)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < input->size)
	{
		j = i + 1;
		while (j < input->size)
		{
			total_pairs++;
			if (input->numbers[i] > input->numbers[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}