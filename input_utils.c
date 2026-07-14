/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:02:19 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/14 19:08:21 by jcesar-o         ###   ########.fr       */
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
