/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:20:30 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/28 17:34:49 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "stack.h"
# include "operations.h"

typedef struct s_algorithm
{
	int		fd;
	t_stack	*a;
	t_stack	*b;
	t_stats	*stats;
}	t_algorithm;

double	compute_disorder(int *numbers, int size);

void	sort_simple(t_algorithm *alg);
void	sort_medium(t_algorithm *alg);
void	sort_complex(t_algorithm *alg);
void	sort_adaptive(t_algorithm *alg);

int		find_index_position(int index, t_stack *stack);
void	assign_sorted_index(t_stack *stack);
void	rotate_to_top(int target, t_algorithm *alg,
		int (*r)(int, t_stack *, t_stats *),
		int (*rr)(int, t_stack *, t_stats *));

#endif
