/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:45:45 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/30 19:40:57 by eduaaugu         ###   ########.fr       */
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

	// Atribuir o índice de cada número na stack.
	rank_index(alg->a);
	
	// Encontrar a quantidade de bits necessária para representar o maior índice.
	bit = 0;
	max_bits = find_max_bits(alg->a->size - 1);
	size = alg->a->size;

	// Percorrer toda a stack A uma vez.
	while (bit < max_bits)
	{
		i = 0;
		// Repetir até analisar todos os elementos de A.
		while (i < size)
		{
			// Se o bit analisado for 0, empurrar o número para B.
			if (((alg->a->top->index >> bit) & 1) == 0)
				pb(alg->b, alg->a, alg->stats);

			// Se o bit analisado for 1, rotacionar A.
			else
				ra(alg->a, alg->stats);
			i++;
		}
		// Passar todos os elementos de B de volta para A.
		while(alg->b->top)
			pa(alg->a, alg->b, alg->stats);
		// Incrementar o bit analisado.
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
