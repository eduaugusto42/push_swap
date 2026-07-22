/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:44:26 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/21 17:15:45 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

typedef struct s_input t_input;

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_operation;

typedef struct s_benchmark
{
	int		active;
	double	disorder;

	char	*strategy;
	char	*complexity;

	int		total_ops;
	int		operation_count[OP_COUNT];

}	t_benchmark;

void	benchmark_init(t_benchmark *bench, t_input *input);
double	compute_disorder(t_input *input);
void	record_operation(t_input *input, t_benchmark *bench, t_operation op);

#endif