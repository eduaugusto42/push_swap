/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:02:17 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/30 17:36:51 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sa(t_stack *a, t_stats *stats);
void	sb(t_stack *b, t_stats *stats);
void	ss(t_stack *a, t_stack *b, t_stats *stats);

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

void	sa(t_stack *a, t_stats *stats)
{
	if (stack_swap(a) == 1)
	{
		stats->op_count[SA]++;
		stats->total++;
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack *b, t_stats *stats)
{
	if (stack_swap(b) == 1)
	{
		stats->op_count[SB]++;
		stats->total++;
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack *a, t_stack *b, t_stats *stats)
{
	if (stack_swap(a) == 1 || stack_swap(b) == 1)
	{
		stats->op_count[SS]++;
		stats->total++;
		ft_putstr_fd("ss\n", 1);
	}
}
