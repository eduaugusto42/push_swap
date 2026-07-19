/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:02:19 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/19 19:07:38 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

long	ft_atol(char *nbr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nbr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nbr[i] == '+')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		result = result * 10 + (nbr[i] - '0');
		i++;
	}
	return (result *= sign);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_input(t_input *input)
{
	if (!input)
		return ;
	if (input->numbers)
		free(input->numbers);
	free(input);
}

int	count_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

int	has_flag_after_number(int argc, char **argv)
{
	int	i;
	int	number_found;

	i = 1;
	number_found = 0;
	while (i < argc)
	{
		if (has_flag_prefix(argv[i]))
		{
			if (number_found)
				return (1);
		}
		else
			number_found = 1;
		i++;
	}
	return (0);
}
