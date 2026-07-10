/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:50:58 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/10 17:31:18 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_push_top(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	node->prev = NULL;
	if (stack->top)
		stack->top->prev = node;
	stack->top = node;
	if (stack->bottom == NULL)
		stack->bottom = node;
	stack->size++;
}

void	stack_push_bottom(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->prev = stack->bottom;
	node->next = NULL;
	if (stack->bottom)
		stack->bottom->next = node;
	stack->bottom = node;
	if (stack->top == NULL)
		stack->top = node;
	stack->size++;
}
