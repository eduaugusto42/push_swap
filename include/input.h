/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:33:50 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/19 13:46:43 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "ft_printf.h"
# include "strategy.h"

typedef struct s_input
{
	int			*numbers;
	int			size;
	t_strategy	strategy;
	int			benchmark;
}	t_input;

t_input	*parse_command_line(int argc, char **argv);
int		is_valid_number(char *token);
int		has_duplicates(int *numbers, int size);
int		parse_token(char *token, int *value);
long	ft_atol(char *nbr);
void	free_matrix(char **matrix);
void	free_input(t_input *input);
int		count_tokens(char **tokens);
int		parse_flags(int argc, char **argv, t_input *input);
int		has_flag_prefix(char *str);
int		has_flag_after_number(int argc, char **argv);

#endif