/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:58:06 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/21 17:18:18 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "benchmark.h"
#include "input.h"
#include "strategy.h"

static const char *g_operation_name[] =
{
	[OP_SA] = "sa",
	[OP_SB] = "sb",
	[OP_SS] = "ss",
	[OP_PA] = "pa",
	[OP_PB] = "pb",
	[OP_RA] = "ra",
	[OP_RB] = "rb",
	[OP_RR] = "rr",
	[OP_RRA] = "rra",
	[OP_RRB] = "rrb",
	[OP_RRR] = "rrr"
};

void	record_operation(t_input *input,
		t_benchmark *benchmark, t_operation op)
{
	if (!input || !benchmark || op >= OP_COUNT)
		return ;
	benchmark->total_ops++;
	if (input->print_operations)
		ft_printf("%s\n", g_operation_name[op]);
	if (benchmark->active)
		benchmark->operation_count[op]++;
}