/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 23:07:49 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/26 17:04:38 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "benchmark.h"
# include "input.h"
# include "stack.h"

// Operations functions;
int	pa(t_input *input, t_stack *a, t_stack *b, t_stats *stats);
int	pb(t_input *input, t_stack *b, t_stack *a, t_stats *stats);
int	sa(t_input *input, t_stack *a, t_stats *stats);
int	sb(t_input *input, t_stack *b, t_stats *stats);
int	ss(t_input *input, t_stack *a, t_stack *b, t_stats *stats);
int	ra(t_input *input, t_stack *a, t_stats *stats);
int	rb(t_input *input, t_stack *b, t_stats *stats);
int	rr(t_input *input, t_stack *a, t_stack *b, t_stats *stats);
int	rra(t_input *input, t_stack *a, t_stats *stats);
int	rrb(t_input *input, t_stack *b, t_stats *stats);
int	rrr(t_input *input, t_stack *a, t_stack *b, t_stats *stats);

# endif
