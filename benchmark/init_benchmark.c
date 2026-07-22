/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_benchmark.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:17:45 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/21 17:16:39 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"
#include "printf.h"
#include "input.h"


void	benchmark_init(t_benchmark *bench, t_input *input)
{
	int i;
	
	bench->active = input->benchmark;
	bench->disorder = compute_disorder(input);
	bench->strategy = input->strategy;
	bench->complexity = NULL;
	bench->total_ops = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		bench->operation_count[i] = 0;
		i++;
	}
}
