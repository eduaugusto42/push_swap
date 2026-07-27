/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:15:15 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/26 17:05:18 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	rra(t_input *input, t_stack *a, t_stats *stats);
int	rrb(t_input *input, t_stack *b, t_stats *stats);
int	rrr(t_input *input, t_stack *a, t_stack *b, t_stats *stats);

int	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return (0);
	node = stack_pop_bottom(stack);
	stack_push_top(stack, node);
	return (1);
}

int	rra(t_input *input, t_stack *a, t_stats *stats)
{
	if (reverse_rotate(a) == 1)
	{
		stats->op_count[RRA]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("rra\n");
		return (1);
	}
	return (0);
}

int	rrb(t_input *input, t_stack *b, t_stats *stats)
{
	if (reverse_rotate(b) == 1)
	{
		stats->op_count[RRB]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

int	rrr(t_input *input, t_stack *a, t_stack *b, t_stats *stats)
{
	if (reverse_rotate(a) == 1 || reverse_rotate(b) == 1)
	{
		stats->op_count[RRR]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
