/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:58:06 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/23 19:05:46 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "benchmark.h"
#include "input.h"

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
