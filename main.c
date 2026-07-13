/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:32:07 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/12 21:42:10 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_input	*input;
	int		i;

	input = parse_command_line(argc, argv);
	if (!input)
	{
		printf("Erro no parser\n");
		return (1);
	}

	printf("Quantidade de numeros: %d\n", input->size);

	i = 0;
	while (i < input->size)
	{
		printf("numbers[%d] = %d\n", i, input->numbers[i]);
		i++;
	}

	free_input(input);
	return (0);
}
