/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:49:23 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/30 12:07:48 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	rank_index(t_stack *stack)
{
	t_node	*cursor;
	t_node	*order;

	order = stack->top;
	while (order)
	{
		cursor = stack->top;
		while (cursor)
		{
			if (order->value >= cursor->value)
				order->index++;
			cursor = cursor->next;
		}
		order = order->next;
	}
}

int	find_index_position(int index, t_stack *stack)
{
	int			position;
	t_node		*current;

	position = 0;
	current = stack->top;
	while (current && current->index != index)
	{
		position++;
		current = current->next;
	}
	return (position);
}

void	rotate_to_top(int target, t_algorithm *alg,
		void (*r)(t_stack *, t_stats *),
		void (*rr)(t_stack *, t_stats *))
{
	int		position;
	t_stack *stack;

	if (!alg)
		return ;
	if (r == ra)
		stack = alg->a;
	else if (r == rb)
		stack = alg->b;
	else
		return ;
	if (!stack)
		return ;
	position = find_index_position(target, stack);
	if (stack->size / 2 >= position)
		while (stack->top->index != target)
			r(stack, alg->stats);
	else
		while (stack->top->index != target)
			rr(stack, alg->stats);
}
