/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:47:27 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/23 18:52:55 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "operations.h"

void	assign_index(t_stack *stack);
int		ft_sqrt(int nb);

void	sort_medium(t_stack *a, t_stack *b, t_stats *stats, int fd)
{
	int		rank;
	t_node	*cursor;

	rank = ft_sqrt(a->size);
	while (a->top)
	{
		cursor = a->top;
		while (cursor->index < rank)
			cursor = cursor->next;
		while (a->top->value != cursor->value)
			ra(fd, a, stats); // TODO Uma forma de usar rra quando for oportuno;
		pa(fd, a, b, stats);
		if (b->size == rank) // TODO Esse 'if' não funciona em caso de raiz relativa;
			rank += rank;
	}
}

void	assign_index(t_stack *stack)
{
	t_node *cursor;
	t_node *order;

	order = stack->top;
	while (order)
	{
		cursor = stack->top;
		while (cursor)
		{
			if (order->value >= cursor->value)
				order->index++;
			cursor = cursor->next;
		}
		order = order->next;
	}
}

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	i = 1;
	while (i < nb)
	{
		if (i * i >= nb)
			return (i);
		i++;
	}
	return (0);
}
