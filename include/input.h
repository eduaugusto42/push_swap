/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:33:50 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/22 21:40:55 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "ft_printf.h"

typedef enum e_strategy
{
	INVALID_STRATEGY,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_input
{
	int			*numbers;
	int			size;
	t_strategy	strategy;
	int			benchmark;
	int		print_operations;
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
