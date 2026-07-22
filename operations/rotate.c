/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:38:17 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/21 23:15:31 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	ra(int fd, t_stack *a, t_stats stats);
int	rb(int fd, t_stack *b, t_stats stats);
int	rr(int fd, t_stack *a, t_stack *b, t_stats stats);

int	stack_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return (0);
	node = stack_pop_top(stack);
	stack_push_bottom(stack, node);
	return (1);
}

int	ra(int fd, t_stack *a, t_stats stats)
{
	if (stack_rotate(a) == 1)
	{
		stats->ra++;
		stats->total++;
		if (fd == 1)
			ft_printf("ra\n");
		return (1);
	}
	return (0);
}

int	rb(int fd, t_stack *b, t_stats stats)
{
	if (stack_rotate(b) == 1)
	{
		stats->rb++;
		stats->total++;
		if (fd == 1)
			ft_printf("rb\n");
		return (1);
	}
	return (0);
}

int	rr(int fd, t_stack *a, t_stack *b, t_stats stats)
{
	if (stack_rotate(a) == 1 || stack_rotate(b) == 1)
	{
		stats->rr++;
		stats->total++;
		if (fd == 1)
			ft_printf("rr\n");
		return (1);
	}
	return (0);
}
