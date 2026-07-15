/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:50:50 by juliopestan       #+#    #+#             */
/*   Updated: 2026/07/14 19:08:39 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static int	count_numbers(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tokens;
	int		total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (-1);
		j = 0;
		while (tokens[j])
		{
			total++;
			j++;
		}
		free_matrix(tokens);
		i++;
	}
	return (total);
}

static int	fill_tokens(t_input *input, char **tokens, int *index)
{
	int	j;
	int	value;

	j = 0;
	while (tokens[j])
	{
		if (!parse_token(tokens[j], &value))
			return (0);
		input->numbers[*index] = value;
		(*index)++;
		j++;
	}
	return (1);
}

static int	fill_numbers(t_input *input, int argc, char **argv)
{
	int		i;
	int		index;
	char	**tokens;

	i = 1;
	index = 0;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		if (!fill_tokens(input, tokens, &index))
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
	input->numbers = NULL;
	input->size = count_numbers(argc, argv);
	if (input->size == -1)
	{
		free_input(input);
		return (NULL);
	}
	input->numbers = malloc(sizeof(int) * input->size);
	if (!input->numbers)
	{
		free_input(input);
		return (NULL);
	}
	return (input);
}

t_input	*parse_command_line(int argc, char **argv)
{
	t_input	*input;

	input = init_input(argc, argv);
	if (!input)
		return (NULL);
	if (!fill_numbers(input, argc, argv))
	{
		free_input(input);
		return (NULL);
	}
	if (has_duplicates(input->numbers, input->size))
	{
		free_input(input);
		return (NULL);
	}
	return (input);
}
