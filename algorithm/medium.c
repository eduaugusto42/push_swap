/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:47:27 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/29 16:15:00 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "operations.h"

int		ft_sqrt(int nb);

void	sort_medium(t_algorithm *alg)
{
	int		chunk;
	int		chunk_size;
	int		target;
	t_node	*current;

	assign_sorted_index(alg->a);
	chunk = 1;
	chunk_size = ft_sqrt(alg->a->size);
	while (alg->a->top)
	{
		while(alg->a->top && alg->b->size < chunk * chunk_size)
		{
			current = alg->a->top; // TODO current pode virar null e dar seg fault;
				current = current->next;
			rotate_to_top(current->index, alg, ra, rra);
			pb(alg->fd, alg->b, alg->a, alg->stats);
		}
		chunk++;
	}
	target = alg->b->size - 1;
	while(alg->b->top)
	{
		rotate_to_top(target, alg, rb, rrb);
		pa(alg->fd, alg->a, alg->b, alg->stats);
		target--;
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
