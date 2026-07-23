/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:31:27 by eduaaugu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/21 21:54:21 by eduaaugu         ###   ########.fr       */
=======
/*   Updated: 2026/07/21 23:14:09 by eduaaugu         ###   ########.fr       */
>>>>>>> origin/operations
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_H
# define STACK_H

# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

// Stack lifecycle;
void	stack_init(t_stack *stack);
void	stack_clear(t_stack *stack);

// Node lifecycle;
t_node 	*node_new(int value);

// Stack primitive operations;
void	stack_push_top(t_stack *stack, t_node *node);
void	stack_push_bottom(t_stack *stack, t_node *node);
t_node	*stack_pop_top(t_stack *stack);
t_node	*stack_pop_bottom(t_stack *stack);

// Bridge from parser to stack
int	stack_fill_from_array(t_stack *stack, int *numbers, int size);

#endif
