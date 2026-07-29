/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:20:30 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/29 18:45:07 by jcesar-o         ###   ########.fr       */
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
}	t_algorithm;

//double	compute_disorder(int *numbers, int size);

void	sort_simple(t_algorithm *alg);
void	sort_medium(t_algorithm *alg);
//void	sort_complex(t_algorithm *alg);
//void	sort_adaptive(t_algorithm *alg);

int		find_index_position(int index, t_stack *stack);
void	assign_sorted_index(t_stack *stack);
void	rotate_to_top(int target, t_algorithm *alg,
		void (*r)(t_stack *, t_stats *),
		void (*rr)(t_stack *, t_stats *));

#endif
