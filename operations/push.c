/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:58:19 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/21 23:14:55 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	pa(int fd, t_stack *a, t_stack *b, t_stats stats);
int	pb(int fd, t_stack *b, t_stack *a, t_stats stats);

int	stack_push(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !b)
		return (0);
	node = stack_pop_top(b);
	stack_push_top(a, node);
	return (1);
}

int	pa(int fd, t_stack *a, t_stack *b, t_stats stats)
{
	if (stack_push(a, b) == 1)
	{
		stats->pa++;
		stats->total++;
		if (fd == 1)
			ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	pb(int fd, t_stack *b, t_stack *a, t_stats stats)
{
	if (stack_push(a, b) == 1)
	{
		stats->pb++;
		stats->total++;
		if (fd == 1)
			ft_printf("pb\n");
		return (1);
	}
	return (0);
}
