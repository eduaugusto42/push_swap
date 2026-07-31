/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:54:52 by juliopestan       #+#    #+#             */
/*   Updated: 2026/07/31 11:40:53 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	has_flag_prefix(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '-' && str[1] == '-')
		return (1);
	return (0);
}

static t_strategy	get_strategy(char *str)
{
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (SIMPLE);
	else if (ft_strncmp(str, "--medium", 9) == 0)
		return (MEDIUM);
	else if (ft_strncmp(str, "--complex", 10) == 0)
		return (COMPLEX);
	else if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (ADAPTIVE);
	return (NO_STRATEGY);
}

static int	process_benchmark(char *str, t_input *input)
{
	if (ft_strncmp(str, "--bench", 8) != 0)
		return (0);
	if (input->benchmark)
		return (0);
	input->benchmark = 1;
	return (1);
}

static int	process_flag(char *str, t_input *input)
{
	t_strategy	strategy;

	strategy = get_strategy(str);
	if (strategy != NO_STRATEGY)
	{
		if (input->strategy != NO_STRATEGY)
			return (0);
		input->strategy = strategy;
		return (1);
	}
	return (process_benchmark(str, input));
}

int	parse_flags(int argc, char **argv, t_input *input)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (has_flag_prefix(argv[i]))
		{
			if (!process_flag(argv[i], input))
				return (0);
		}
		i++;
	}
	if (input->strategy == NO_STRATEGY)
		input->strategy = ADAPTIVE;
	return (1);
}
