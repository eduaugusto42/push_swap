/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:02:17 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/20 19:17:34 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int	sa(t_stack *a);
int	sb(t_stack *b);
int	ss(t_stack *a, t_stack *b);

int	stack_swap(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

if (!stack || stack->size < 2)
		return (0);
	a = stack_pop_top(stack);
	b = stack_pop_top(stack);
	stack_push_top(stack, a);
	stack_push_top(stack, b);
	return (1);
}

int	sa(t_stack *a)
{
	return (stack_swap(a));
}

int	sb(t_stack *b)
{
	return (stack_swap(b));
}

int	ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	return (stack_swap(b));
}
