/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:59:38 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/31 17:30:22 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "stack.h"
#include "algorithm.h"
#include "benchmark.h"

int			cleanup(t_algorithm *alg, t_input *input);
t_algorithm *algorithm_init(void);
t_algorithm	*free_algorithm(t_algorithm *alg);
void		choose_algorithm(t_algorithm *alg, t_input *input);

int	main(int argc, char **argv)
{
	t_algorithm	*alg;
	t_input		*input;

	if (argc == 1)
		return (0);
	alg = algorithm_init();
	if (!alg)
	{
		ft_printf("Error\n");
		return (1);
	}
	input = parse_command_line(argc, argv);
	if (!input)
	{
		free_algorithm(alg);
		ft_printf("Error\n");
		return (1);
	}
	if (stack_fill_from_array(alg->a, input->numbers, input->size) == 0
			|| input->disorder == 0)
		return (cleanup(alg, input));
	choose_algorithm(alg, input);
	print_bench(input, alg->stats);
	return (cleanup(alg, input));
}

t_algorithm *algorithm_init(void)
{
    t_algorithm *alg;

    alg = malloc(sizeof(t_algorithm));
    if (!alg)
        return (NULL);
    alg->a = malloc(sizeof(t_stack));
    if (!alg->a)
        return (free_algorithm(alg));
    alg->b = malloc(sizeof(t_stack));
    if (!alg->b)
        return (free_algorithm(alg));
    alg->stats = init_stats();
    if (!alg->stats)
        return (free_algorithm(alg));
    stack_init(alg->a);
    stack_init(alg->b);
    return (alg);
}

t_algorithm	*free_algorithm(t_algorithm *alg)
{
	if (!alg)
		return (NULL);
	free(alg->a);
	free(alg->b);
	free(alg->stats);
	free(alg);
	return (NULL);
}

int	cleanup(t_algorithm *alg, t_input *input)
{
	free_algorithm(alg);
	free_input(input);
	return (0);
}

void	choose_algorithm(t_algorithm *alg, t_input *input)
{
	if ((input->disorder <= 0.2 && input->strategy == ADAPTIVE)
		|| input->strategy == SIMPLE)
		simple_sort(alg);
	else if ((input->disorder <= 0.5 && input->strategy == ADAPTIVE)
		|| input->strategy == MEDIUM)
		chunk_sort(alg);
	else
		radix_sort(alg);
}
