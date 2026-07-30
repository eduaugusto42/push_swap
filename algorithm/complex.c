/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:45:45 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/30 16:49:10 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "operations.h"

void	k_sort(t_algorithm *alg)
{
	int	delta;

	rank_index(alg->a);
	delta = alg->a->size / 20 + 7;
	while (alg->a->top)
	{
		if (alg->a->top->index <= alg->b->size + delta)
		{
			pb(alg->b, alg->a, alg->stats);
			if (alg->b->top->index <= alg->b->size)
				rb(alg->b, alg->stats);
		}
		else
			ra(alg->a, alg->stats);
	}
	while (alg->b->top)
	{
		rotate_to_top(alg->b->size - 1, alg, rb, rrb);
		pa(alg->a, alg->b, alg->stats);
	}
}
