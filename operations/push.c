/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:58:19 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/17 16:10:48 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);

void	stack_push(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !b)
		return ;
	node = stack_pop_top(b);
	stack_push_top(a, node);
}

void	pa(t_stack *a, t_stack *b)
{
	stack_push(a, b);
}

void	pb(t_stack *b, t_stack *a)
{
	stack_push(a, b);
}
