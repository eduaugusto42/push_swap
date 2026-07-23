/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:44:22 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/23 16:37:37 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "operations.h"

void	assign_index(t_stack *stack);

void	sort_simple(t_stack *a, t_stack *b, t_stats *stats, int fd)
{
	t_node	*cursor;
	t_node	*smallest;

	while (a->top)
	{
		cursor = a->top;
		smallest = a->top;
		while (cursor)
		{
			cursor = cursor->next;
			if (cursor && cursor->value < smallest->value)
				smallest = cursor;
		}
		assign_index(a);
		if (a->size / 2 >= smallest->index)
			while(a->top->value != smallest->value)
				ra(fd, a, stats);
		else
			while(a->top->value != smallest->value)
				rra(fd, a, stats);
		pb(fd, b, a, stats);
	}
	while(b->top)
		pa(fd, a, b, stats);
}

void	assign_index(t_stack *stack)
{
	int		order;
	t_node	*cursor;

	order = 0;
	cursor = stack->top;
	while (cursor)
	{
		cursor->index = order++;
		cursor = cursor->next;
	}
}

