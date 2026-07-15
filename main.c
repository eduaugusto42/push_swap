/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:32:07 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/15 19:33:20 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_input	*input;
	int		i;

	if (argc == 1)
		return (0);
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
