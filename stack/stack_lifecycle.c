/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:51:26 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/20 18:36:29 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	stack_clear(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return ;
	while (stack->top != NULL)
	{
		node = stack_pop_top(stack);
		free(node);
	}
}

int	stack_fill_from_array(t_stack *stack, int *numbers, int size)
{
	int		i;
	t_node	*node;

	if (!stack || size < 0 || (!numbers && size > 0))
		return (0);
	i = 0;
	while (i < size)
	{
		node = node_new(numbers[i]);
		if (!node)
		{
			stack_clear(stack);
			return (0);
		}
		stack_push_bottom(stack, node);
		i++;
	}
	return (1);
}
