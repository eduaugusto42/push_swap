/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:58:19 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/20 19:09:25 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	pa(t_stack *a, t_stack *b);
int	pb(t_stack *b, t_stack *a);

int	stack_push(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !b)
		return (0);
	node = stack_pop_top(b);
	stack_push_top(a, node);
	return (1);
}

int	pa(t_stack *a, t_stack *b)
{
	return (stack_push(a, b));
}

int	pb(t_stack *b, t_stack *a)
{
	return (stack_push(a, b));
}
