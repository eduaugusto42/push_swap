/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_benchmark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 20:00:46 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/08/01 18:53:51 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "input.h"
#include "benchmark.h"

const char	*strategy_name(t_input *input)
{
	if (input->strategy == SIMPLE)
		return ("Simple");
	if (input->strategy == MEDIUM)
		return ("Medium");
	if (input->strategy == COMPLEX)
		return ("Complex");
	if (input->strategy == ADAPTIVE)
		return ("Adaptive");
	return ("Unknown");
}

const char	*strategy_complexity(t_input *input)
{
	if (input->disorder <= 0.2 || input->strategy == SIMPLE)
		return ("O(n²)");
	if (input->disorder <= 0.5 || input->strategy == MEDIUM)
		return ("O(n√n)");
	if (input->disorder <= 1 || input->strategy == COMPLEX)
		return ("O(n log n)");
	if (input->strategy == ADAPTIVE)
	{
		if (input->disorder <= 0.2)
			return ("O(n²)");
		else if (input->disorder <= 0.5)
			return ("O(n√n)");
		else
			return ("O(n log n)");
	}
	return (NULL);
}

void	print_operations(t_stats *stats)
{
	const char	*g_operation_name[] = {
	[SA] = "sa",
	[SB] = "sb",
	[SS] = "ss",
	[PA] = "pa",
	[PB] = "pb",
	[RA] = "ra",
	[RB] = "rb",
	[RR] = "rr",
	[RRA] = "rra",
	[RRB] = "rrb",
	[RRR] = "rrr"
	};
	int			i;

	i = 0;
	while (i < COUNT)
	{
		ft_printf("%s: %d  ",
			g_operation_name[i], stats->op_count[i]);
		if (i == 4)
			ft_printf("\n[BENCH] ");
		i++;
	}
}

void	print_bench(t_input *input, t_stats *stats)
{
	int	percent;
	int	decimal;

	if (input->benchmark)
	{
		percent = (int)(input->disorder * 100);
		decimal = (int)(input->disorder * 10000) % 100;
		ft_printf("[BENCH] disorder: %d.", percent);
		if (decimal < 10)
			ft_printf("0");
		ft_printf("%d%%\n", decimal);
		ft_printf("[BENCH] strategy: %s / %s\n",
			strategy_name(input), strategy_complexity(input));
		ft_printf("[BENCH] total_ops: %d\n", stats->total);
		ft_printf("[BENCH] ");
		print_operations(stats);
		ft_printf("\n");
	}
}
