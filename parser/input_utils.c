/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:02:19 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/26 15:59:48 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "libft.h"

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

t_input	*free_input(t_input *input)
{
	if (!input)
		return (NULL);
	if (input->numbers)
		free(input->numbers);
	free(input);
	return (NULL);
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