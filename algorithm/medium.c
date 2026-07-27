/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:47:27 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/27 17:27:47 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "operations.h"

int		ft_sqrt(int nb);
void	assign_medium(t_stack *stack);
void	a_rotation(int fd, t_stack *stack, t_stats *stats, int target);
void	b_rotation(int fd, t_stack *stack, t_stats *stats, int target);

void	sort_medium(t_stack *a, t_stack *b, t_stats *stats, int fd)
{
	int	chunk;
	int	size;
	int	target;
	t_node	*current;

	assign_medium(a);
	chunk = 1;
	size = ft_sqrt(a->size);
	while (a->top)
	{
		while (b->size < chunk * size) // BUG: Se raiz não for exata;
		{
			current = a->top;
			while (current && chunk * size <= current->index)
				current = current->next;
			a_rotation(fd, a, stats, current->index); // BUG: se current == NULL;
			pb(fd, b, a, stats);
		}
		chunk++;
	}
	target = b->size - 1;
	while (b->top)
	{
		b_rotation(fd, b, stats, target);
		pa(fd, a, b, stats);
		target--;
	}
}

void	assign_medium(t_stack *stack)
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
	long int	i;

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

void	a_rotation(int fd, t_stack *stack, t_stats *stats, int target)
{
	int		target_position;
	t_node	*cursor;

	target_position = 0;
	cursor = stack->top;
	while (cursor->index != target)
	{
		target_position++;
		cursor = cursor->next;
	}
	if (stack->size / 2 >= target_position)
		while (stack->top->index != target)
			ra(fd, stack, stats);
	else
		while (stack->top->index != target)
			rra(fd, stack, stats);
}

void	b_rotation(int fd, t_stack *stack, t_stats *stats, int target) // Deletar e fazer uma função só;
{
	int		target_position;
	t_node	*cursor;

	target_position = 0;
	cursor = stack->top;
	while (cursor->index != target)
	{
		target_position++;
		cursor = cursor->next;
	}
	if (stack->size / 2 >= target_position)
		while (stack->top->index != target)
			rb(fd, stack, stats);
	else
		while (stack->top->index != target)
			rrb(fd, stack, stats);
}
