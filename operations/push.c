/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:58:19 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/26 19:08:10 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

int	pa(t_input *input, t_stack *a, t_stack *b, t_stats *stats);
int	pb(t_input *input, t_stack *b, t_stack *a, t_stats *stats);

int	stack_push(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !b)
		return (0);
	node = stack_pop_top(b);
	stack_push_top(a, node);
	return (1);
}

int	pa(t_input *input, t_stack *a, t_stack *b, t_stats *stats)
{
	if (stack_push(a, b) == 1)
	{
		stats->op_count[PA]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	pb(t_input *input, t_stack *b, t_stack *a, t_stats *stats)
{
	if (stack_push(b, a) == 1)
	{
		stats->op_count[PB]++;
		stats->total++;
		if (input->fd == 1)
			ft_printf("pb\n");
		return (1);
	}
	return (0);
}
