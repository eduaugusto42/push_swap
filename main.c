/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:59:38 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/29 19:23:40 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "input.h"
#include "stack.h"
#include "algorithm.h"
#include "benchmark.h"
#include <stdio.h>

t_algorithm	*init_algorithm(t_stack *a, t_stack *b, t_stats *stats);

int	main(int argc, char **argv)
{
	t_input	*input;
	t_stats	*stats;
	t_algorithm *alg;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	stack_init(a);
	stack_init(b);
	input = parse_command_line(argc, argv);
	if (!input)
	{
		printf("Error\n");
		return (1);
	}
	stack_fill_from_array(a, input->numbers, input->size);
	stats = init_stats();
	alg = init_algorithm(a, b, stats);
	if (input->disorder == 0)
		return (0);
	if (input->disorder <= 0.2)
		sort_simple(alg);
	print_banch(input, stats);
	return (0);
}

t_algorithm	*init_algorithm(t_stack *a, t_stack *b, t_stats *stats)
{
	t_algorithm *alg;

	alg = malloc(sizeof(t_algorithm));
	if (!alg)
		return (NULL);
	alg->a = a;
	alg->b = b;
	alg->stats = stats;
	return (alg);
}
