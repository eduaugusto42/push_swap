/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:02:17 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/26 14:36:14 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	sa(t_input *input, t_stack *a, t_stats *stats);
int	sb(t_input *input, t_stack *b, t_stats *stats);
int	ss(t_input *input, t_stack *a, t_stack *b, t_stats *stats);

int	stack_swap(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (!stack || stack->size < 2)
		return (0);
	a = stack_pop_top(stack);
	b = stack_pop_top(stack);
	stack_push_top(stack, a);
	stack_push_top(stack, b);
	return (1);
}

int	sa(t_input *input, t_stack *a, t_stats *stats)
{
	if (stack_swap(a) == 1)
	{
		stats->op_count[SA]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("sa\n");
		return (1);
	}
	return (0);
}

int	sb(t_input *input, t_stack *b, t_stats *stats)
{
	if (stack_swap(b) == 1)
	{
		stats->op_count[SB]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("sb\n");
		return (1);
	}
	return (0);
}

int	ss(t_input *input, t_stack *a, t_stack *b, t_stats *stats)
{
	if (stack_swap(a) == 1 || stack_swap(b) == 1)
	{
		stats->op_count[SS]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("ss\n");
		return (1);
	}
	return (0);
}
