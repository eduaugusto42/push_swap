/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:44:22 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/08/03 15:20:29 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	selection_sort(t_algorithm *alg);
void	tiny_sort(t_algorithm *alg);

void	simple_sort(t_algorithm *alg)
{
	if (alg->a->size == 2)
		sa(alg->a, alg->stats);
	else if (alg->a->size == 3)
		tiny_sort(alg);
	else
		selection_sort(alg);
}

void	tiny_sort(t_algorithm *alg)
{
	t_stack	*stack;

	stack = alg->a;
	rank_index(stack);
	if ((stack->top->index == 0 && stack->bottom->index == 1)
		|| (stack->top->index == 1 && stack->bottom->index == 2)
		|| (stack->top->index == 2 && stack->bottom->index == 0))
		sa(stack, alg->stats);
	if (stack->top->index == 2 && stack->bottom->index == 1)
		ra(stack, alg->stats);
	if (stack->top->index == 1 && stack->bottom->index == 0)
		rra(stack, alg->stats);
}

void	selection_sort(t_algorithm *alg)
{
	int	i;

	i = 0;
	rank_index(alg->a);
	while (alg->a->size > 1)
	{
		rotate_to_top(i, alg, ra, rra);
		pb(alg->b, alg->a, alg->stats);
		i++;
	}
	while (alg->b->top)
		pa(alg->a, alg->b, alg->stats);
}
