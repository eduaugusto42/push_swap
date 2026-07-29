/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:15:15 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/29 16:40:31 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_stack *a, t_stats *stats);
void	rrb(t_stack *b, t_stats *stats);
void	rrr(t_stack *a, t_stack *b, t_stats *stats);

int	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return (0);
	node = stack_pop_bottom(stack);
	stack_push_top(stack, node);
	return (1);
}

void	rra(t_stack *a, t_stats *stats)
{
	if (reverse_rotate(a) == 1)
	{
		stats->rra++;
		stats->total++;
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_stack *b, t_stats *stats)
{
	if (reverse_rotate(b) == 1)
	{
		stats->rrb++;
		stats->total++;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_stack *a, t_stack *b, t_stats *stats)
{
	if (reverse_rotate(a) == 1 || reverse_rotate(b) == 1)
	{
		stats->rrr++;
		stats->total++;
		ft_putstr_fd("rrr\n", 1);
	}
}
