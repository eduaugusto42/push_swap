/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:38:17 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/20 19:12:24 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ra(t_stack *a);
int	rb(t_stack *b);
int	rr(t_stack *a, t_stack *b);

int	stack_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return (0);
	node = stack_pop_top(stack);
	stack_push_bottom(stack, node);
	return (1);
}

int	ra(t_stack *a)
{
	return (stack_rotate(a));
}

int	rb(t_stack *b)
{
	return (stack_rotate(b));
}

int	rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	return (stack_rotate(b));
}
