/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:47:27 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/08/03 14:58:44 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "operations.h"

int	ft_sqrt(int nb);
int	chunk_exists(t_stack *stack, int chunk, int chunk_size);
int	find_best_chunk_target(t_stack *stack, int chunk, int chunk_size);

void	chunk_sort(t_algorithm *alg)
{
	int		chunk;
	int		chunk_size;
	int		target;

	chunk = 0;
	chunk_size = ft_sqrt(alg->a->size);
	rank_index(alg->a);
	while (alg->a->top)
	{
		while (chunk_exists(alg->a, chunk, chunk_size))
		{
			target = find_best_chunk_target(alg->a, chunk, chunk_size);
			rotate_to_top(target, alg, ra, rra);
			pb(alg->b, alg->a, alg->stats);
		}
		chunk++;
	}
	target = alg->b->size - 1;
	while (alg->b->top)
	{
		rotate_to_top(target, alg, rb, rrb);
		pa(alg->a, alg->b, alg->stats);
		target--;
	}
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

int	chunk_exists(t_stack *stack, int chunk, int chunk_size)
{
	t_node		*current;

	current = stack->top;
	while (current)
	{
		if (chunk * chunk_size <= current->index
			&& current->index < (chunk + 1) * chunk_size)
			return (1);
		current = current->next;
	}
	return (0);
}

int	find_best_chunk_target(t_stack *stack, int chunk, int chunk_size)
{
	int		top_position;
	int		bottom_position;
	t_node	*top;
	t_node	*bottom;

	top_position = 0;
	top = stack->top;
	while (!(chunk * chunk_size <= top->index
			&& top->index < (chunk + 1) * chunk_size))
	{
		top_position++;
		top = top->next;
	}
	bottom_position = 0;
	bottom = stack->bottom;
	while (!(chunk * chunk_size <= bottom->index
			&& bottom->index < (chunk + 1) * chunk_size))
	{
		bottom_position++;
		bottom = bottom->prev;
	}
	if (top_position <= bottom_position)
		return (top->index);
	else
		return (bottom->index);
}
