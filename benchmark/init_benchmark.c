/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_benchmark.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:17:45 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/24 15:46:32 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"
#include "printf.h"
#include "input.h"


void	benchmark_init(t_benchmark *bench, t_input *input)
{	
	bench->active = input->benchmark;
	bench->disorder = input->disorder;
	bench->strategy = input->strategy;
	bench->complexity = NULL;
	bench->stats = NULL;
}
