/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:39:58 by juliopestan       #+#    #+#             */
/*   Updated: 2026/07/31 11:41:26 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "libft.h"

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

int	has_duplicates(t_input *input)
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
