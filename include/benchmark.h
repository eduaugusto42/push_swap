/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:44:26 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/29 18:51:46 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

# include "ft_printf.h"

typedef struct s_input t_input;

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	COUNT
}	t_operation;

typedef struct s_stats
{
	int	total;
	int	op_count[COUNT];
}	t_stats;

t_stats	*init_stats(void);
t_stats	*init_algorithm(void);
void	print_banch(t_input *input, t_stats *stats);

#endif