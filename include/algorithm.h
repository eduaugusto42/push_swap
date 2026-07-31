/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:20:30 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/31 18:02:03 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "stack.h"
# include "operations.h"
# include "input.h"

typedef struct s_algorithm
{
	t_stack	*a;
	t_stack	*b;
	t_stats	*stats;
	t_input	*input;
}	t_algorithm;

void	simple_sort(t_algorithm *alg);
void	chunk_sort(t_algorithm *alg);
void	radix_sort(t_algorithm *alg);

int		find_index_position(int index, t_stack *stack);
void	rank_index(t_stack *stack);
void	rotate_to_top(int target, t_algorithm *alg,
			void (*r)(t_stack *, t_stats *),
			void (*rr)(t_stack *, t_stats *));

#endif
