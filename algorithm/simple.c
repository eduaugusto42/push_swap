/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:44:22 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/26 17:25:54 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "stack.h"
# include "operations.h"
# include "algorithm.h"
# include "benchmark.h"

void	assign_index(t_stack *stack);

void	sort_simple(t_stack *a, t_stack *b, t_stats *stats, t_input *input)
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
				ra(input, a, stats);
		else
			while(a->top->value != smallest->value)
				rra(input, a, stats);
		pb(input, b, a, stats);
	}
	while(b->top)
		pa(input, a, b, stats);
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

