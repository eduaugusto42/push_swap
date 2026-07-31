/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:33:50 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/31 17:14:21 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "libft.h"

typedef enum e_strategy
{
	NO_STRATEGY,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_input
{
	t_strategy	strategy;
	int			benchmark;
	int			*numbers;
	int			size;
	double		disorder;
}	t_input;

t_input	*parse_command_line(int argc, char **argv);
int		has_flag_after_number(int argc, char **argv);
int		parse_flags(int argc, char **argv, t_input *input);
int		has_flag_prefix(char *str);
int		convert_to_int(char *token, int *value);
int		is_valid_number(char *token);
int		has_duplicates(t_input *input);
long	ft_atol(char *nbr);
void	free_matrix(char **matrix);
t_input	*free_input(t_input *input);
int		count_tokens(char **tokens);
double	compute_disorder(t_input *input);

#endif
