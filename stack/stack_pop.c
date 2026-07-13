/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:59:41 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/13 19:37:15 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_pop_top(t_stack *stack)
{
	t_node	*pop_top;

	if (!stack || !stack->top)
		return (NULL);

	pop_top = stack->top;
	stack->top = pop_top->next;
	if (!stack->top)
		stack->bottom = NULL;
	else
		stack->top->prev = NULL;
	pop_top->next = NULL;
	pop_top->prev = NULL;
	stack->size--;
	return (pop_top);
}

t_node	*stack_pop_bottom(t_stack *stack)
{
	t_node	*pop_bottom;

	if (!stack || !stack->bottom)
		return (NULL);

	pop_bottom = stack->bottom;
	stack->bottom = pop_bottom->next;
	if (!stack->bottom)
		stack->top = NULL;
	else
		stack->bottom->prev = NULL;
	pop_bottom->next = NULL;
	pop_bottom->prev = NULL;
	stack->size--;
	return (pop_bottom);
}
