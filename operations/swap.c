/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:02:17 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/23 14:53:32 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	sa(int fd, t_stack *a, t_stats *stats);
int	sb(int fd, t_stack *b, t_stats *stats);
int	ss(int fd, t_stack *a, t_stack *b, t_stats *stats);

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

int	sa(int fd, t_stack *a, t_stats *stats)
{
	if (stack_swap(a) == 1)
	{
		stats->sa++;
		stats->total++;
		if (fd == 1)
			ft_printf("sa\n");
		return (1);
	}
	return (0);
}

int	sb(int fd, t_stack *b, t_stats *stats)
{
	if (stack_swap(b) == 1)
	{
		stats->sb++;
		stats->total++;
		if (fd == 1)
			ft_printf("sb\n");
		return (1);
	}
	return (0);
}

int	ss(int fd, t_stack *a, t_stack *b, t_stats *stats)
{
	if (stack_swap(a) == 1 || stack_swap(b) == 1)
	{
		stats->ss++;
		stats->total++;
		if (fd == 1)
			ft_printf("ss\n");
		return (1);
	}
	return (0);
}
