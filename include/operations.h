/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 23:07:49 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/31 17:22:16 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"
# include "input.h"
# include "benchmark.h"

void	pa(t_stack *a, t_stack *b, t_stats *stats);
void	pb(t_stack *b, t_stack *a, t_stats *stats);
void	sa(t_stack *a, t_stats *stats);
void	sb(t_stack *b, t_stats *stats);
void	ss(t_stack *a, t_stack *b, t_stats *stats);
void	ra(t_stack *a, t_stats *stats);
void	rb(t_stack *b, t_stats *stats);
void	rr(t_stack *a, t_stack *b, t_stats *stats);
void	rra(t_stack *a, t_stats *stats);
void	rrb(t_stack *b, t_stats *stats);
void	rrr(t_stack *a, t_stack *b, t_stats *stats);

#endif
