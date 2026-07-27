/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:38:17 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/26 14:35:33 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	ra(t_input *input, t_stack *a, t_stats *stats);
int	rb(t_input *input, t_stack *b, t_stats *stats);
int	rr(t_input *input, t_stack *a, t_stack *b, t_stats *stats);

int	stack_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return (0);
	node = stack_pop_top(stack);
	stack_push_bottom(stack, node);
	return (1);
}

int	ra(t_input *input, t_stack *a, t_stats *stats)
{
	if (stack_rotate(a) == 1)
	{
		stats->op_count[RA]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("ra\n");
		return (1);
	}
	return (0);
}

int	rb(t_input *input, t_stack *b, t_stats *stats)
{
	if (stack_rotate(b) == 1)
	{
		stats->op_count[RB]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("rb\n");
		return (1);
	}
	return (0);
}

int	rr(t_input *input, t_stack *a, t_stack *b, t_stats *stats)
{
	if (stack_rotate(a) == 1 || stack_rotate(b) == 1)
	{
		stats->op_count[RR]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("rr\n");
		return (1);
	}
	return (0);
}
