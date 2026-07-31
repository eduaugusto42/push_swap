/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:45:45 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/31 11:45:50 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "operations.h"

int	find_max_bits(int index);

void	radix_sort(t_algorithm *alg)
{
	int	bit;
	int	i;
	int	max_bits;
	int	size;

	rank_index(alg->a);
	bit = 0;
	max_bits = find_max_bits(alg->a->size - 1);
	size = alg->a->size;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((alg->a->top->index >> bit) & 1) == 0)
				pb(alg->b, alg->a, alg->stats);
			else
				ra(alg->a, alg->stats);
			i++;
		}
		while (alg->b->top)
			pa(alg->a, alg->b, alg->stats);
		bit++;
	}
}

int	find_max_bits(int index)
{
	int	max_bits;

	max_bits = 0;
	while (index > 0)
	{
		max_bits++;
		index >>= 1;
	}
	return (max_bits);
}
