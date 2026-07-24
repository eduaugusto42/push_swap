/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:44:26 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/24 15:43:19 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

# include "input.h"

typedef struct s_stats
{
	int	total_ops;
	int	op_count[OP_COUNT];
}	t_stats;

typedef struct s_benchmark
{
	int	active;
	double	disorder;
	t_strategy	strategy;
	char	*complexity;
	t_stats	*stats;
}	t_benchmark

void	benchmark_init(t_benchmark *bench, t_input *input);
void	record_operation(t_input *input, t_benchmark *bench, t_operation op);

#endif