/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:58:19 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/29 16:27:58 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pa(t_stack *a, t_stack *b, t_stats *stats);
void	pb(t_stack *b, t_stack *a, t_stats *stats);

int	stack_push(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !b)
		return (0);
	node = stack_pop_top(b);
	stack_push_top(a, node);
	return (1);
}

void	pa(t_stack *a, t_stack *b, t_stats *stats)
{
	if (stack_push(a, b) == 1)
	{
		stats->pa++;
		stats->total++;
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_stack *b, t_stack *a, t_stats *stats)
{
	if (stack_push(b, a) == 1)
	{
		stats->pb++;
		stats->total++;
		ft_putstr_fd("pb\n", 1);
	}
}
