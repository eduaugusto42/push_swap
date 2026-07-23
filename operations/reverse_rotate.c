/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:15:15 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/23 14:54:32 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	rra(int fd, t_stack *a, t_stats *stats);
int	rrb(int fd, t_stack *b, t_stats *stats);
int	rrr(int fd, t_stack *a, t_stack *b, t_stats *stats);

int	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return (0);
	node = stack_pop_bottom(stack);
	stack_push_top(stack, node);
	return (1);
}

int	rra(int fd, t_stack *a, t_stats *stats)
{
	if (reverse_rotate(a) == 1)
	{
		stats->rra++;
		stats->total++;
		if (fd == 1)
			ft_printf("rra\n");
		return (1);
	}
	return (0);
}

int	rrb(int fd, t_stack *b, t_stats *stats)
{
	if (reverse_rotate(b) == 1)
	{
		stats->rrb++;
		stats->total++;
		if (fd == 1)
			ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

int	rrr(int fd, t_stack *a, t_stack *b, t_stats *stats)
{
	if (reverse_rotate(a) == 1 || reverse_rotate(b) == 1)
	{
		stats->rrr++;
		stats->total++;
		if (fd == 1)
			ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
