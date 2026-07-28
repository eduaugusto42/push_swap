/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:44:22 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/28 18:39:29 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "operations.h"

void	sort_simple(t_algorithm *alg)
{
	int	i;

	i = 0;
	assign_sorted_index(alg->a);
	while (alg->a->top)
	{
		rotate_to_top(i, alg, ra, rra);
		pb(alg->fd, alg->b, alg->a, alg->stats);
		i++;
	}
	while (alg->b->top)
		pa(alg->fd, alg->a, alg->b, alg->stats);
}
