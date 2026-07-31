/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:31:27 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/31 17:21:46 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include "input.h"

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

void	stack_init(t_stack *stack);
void	stack_clear(t_stack *stack);

t_node	*node_new(int value);

void	stack_push_top(t_stack *stack, t_node *node);
void	stack_push_bottom(t_stack *stack, t_node *node);
t_node	*stack_pop_top(t_stack *stack);
t_node	*stack_pop_bottom(t_stack *stack);

int		stack_fill_from_array(t_stack *stack, int *numbers, int size);

#endif
