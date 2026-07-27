/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:50:50 by juliopestan       #+#    #+#             */
/*   Updated: 2026/07/26 15:55:58 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "ft_printf.h"
#include "libft.h"

static int	count_numbers(int argc, char **argv)
{
	int		i;
	char	**tokens;
	int		total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		if (has_flag_prefix(argv[i]))
		{
			i++;
			continue ;
		}
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (-1);
		total += count_tokens(tokens);
		free_matrix(tokens);
		i++;
	}
	if (total == 0)
		return (0);
	return (total);
}

static int	fill_numbers(t_input *input, char **tokens, int *index)
{
	int	j;
	int	value;

	j = 0;
	while (tokens[j])
	{
		if (!convert_to_int(tokens[j], &value))
			return (0);
		input->numbers[*index] = value;
		(*index)++;
		j++;
	}
	return (1);
}

static int	parse_numbers(int argc, char **argv, t_input *input)
{
	int		i;
	int		index;
	char	**tokens;

	i = 1;
	index = 0;
	while (i < argc)
	{
		if (has_flag_prefix(argv[i]))
		{
			i++;
			continue ;
		}
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		if (!fill_numbers(input, tokens, &index))
		{
			free_matrix(tokens);
			return (0);
		}
		free_matrix(tokens);
		i++;
	}
	return (1);
}

static t_input	*init_input(int argc, char **argv)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->strategy = NO_STRATEGY;
	input->benchmark = 0;
	input->numbers = NULL;
	input->size = count_numbers(argc, argv);
	input->fd = 1;
	if (input->size == 0)
		return (free_input(input));
	input->numbers = malloc(sizeof(int) * input->size);
	if (!input->numbers)
		return (free_input(input));
	return (input);
}

t_input	*parse_command_line(int argc, char **argv)
{
	t_input	*input;

	if (has_flag_after_number(argc, argv))
		return (NULL);
	input = init_input(argc, argv);
	if (!input)
		return (NULL);
	if (!parse_flags(argc, argv, input))
		return (free_input(input));
	if (!parse_numbers(argc, argv, input))
		return (free_input(input));
	if (has_duplicates(input))
		return (free_input(input));
	input->disorder = compute_disorder(input);
	return (input);
}
