/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:33:50 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/12 21:44:41 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_input
{
	int	*numbers;
	int	size;
}	t_input;

t_input	*parse_command_line(int argc, char **argv);
int	error(void);
int	is_valid_number(char *token);
int	is_int_range(char *token);
void	free_matrix(char **matrix);
void	free_input(t_input *input);
long	ft_atol(char *nbr);

#endif