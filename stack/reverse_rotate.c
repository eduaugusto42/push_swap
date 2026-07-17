/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:15:15 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/17 16:23:36 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack_pop_bottom(stack);
	stack_push_top(stack, node);
}

void	ra(t_stack *a)
{
	reverse_rotate(a);
}

void	rb(t_stack *b)
{
	reverse_rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
