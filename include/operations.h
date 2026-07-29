/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 23:07:49 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/29 16:33:33 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"
# include "input.h"


typedef struct s_stats
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_stats;

// Operations functions;
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

# endif
