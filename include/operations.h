/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 23:07:49 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/23 15:27:09 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"
# include "input.h"
# include "printf.h"


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
int	pa(int fd, t_stack *a, t_stack *b, t_stats *stats);
int	pb(int fd, t_stack *b, t_stack *a, t_stats *stats);
int	sa(int fd, t_stack *a, t_stats *stats);
int	sb(int fd, t_stack *b, t_stats *stats);
int	ss(int fd, t_stack *a, t_stack *b, t_stats *stats);
int	ra(int fd, t_stack *a, t_stats *stats);
int	rb(int fd, t_stack *b, t_stats *stats);
int	rr(int fd, t_stack *a, t_stack *b, t_stats *stats);
int	rra(int fd, t_stack *a, t_stats *stats);
int	rrb(int fd, t_stack *b, t_stats *stats);
int	rrr(int fd, t_stack *a, t_stack *b, t_stats *stats);

# endif
