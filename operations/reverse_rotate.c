/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:15:15 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/20 19:18:18 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	rra(t_stack *a);
int	rrb(t_stack *b);
int	rrr(t_stack *a, t_stack *b);

int	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return (0);
	node = stack_pop_bottom(stack);
	stack_push_top(stack, node);
	return (1);
}

int	rra(t_stack *a)
{
	return (reverse_rotate(a));
}

int	rrb(t_stack *b)
{
	return (reverse_rotate(b));
}

int	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	return (reverse_rotate(b));
}
