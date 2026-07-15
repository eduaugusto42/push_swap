/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:33:50 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/15 15:42:33 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "ft_printf.h"

typedef struct s_input
{
	int	*numbers;
	int	size;
}	t_input;

t_input	*parse_command_line(int argc, char **argv);
int		is_valid_number(char *token);
int		is_int_range(char *token);
int		has_duplicates(int *numbers, int size);
int		parse_token(char *token, int *value);
long	ft_atol(char *nbr);
void	free_matrix(char **matrix);
void	free_input(t_input *input);

#endif