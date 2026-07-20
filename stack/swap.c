/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:02:17 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/17 16:14:48 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	stack_swap(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

if (!stack || stack->size < 2)
		return ;
	a = stack_pop_top(stack);
	b = stack_pop_top(stack);
	stack_push_top(stack, a);
	stack_push_top(stack, b);
}

void	sa(t_stack *a)
{
	stack_swap(a);
}

void	sb(t_stack *b)
{
	stack_swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
}
