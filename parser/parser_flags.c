/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:54:52 by juliopestan       #+#    #+#             */
/*   Updated: 2026/07/19 13:34:31 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "strategy.h"

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
	if (!str)
		return (INVALID_STRATEGY);
	if (ft_strncmp(str, "--simple", ft_strlen("--simple") + 1) == 0)
		return (SIMPLE);
	else if (ft_strncmp(str, "--medium", ft_strlen("--medium") + 1) == 0)
		return (MEDIUM);
	else if (ft_strncmp(str, "--complex", ft_strlen("--complex") + 1) == 0)
		return (COMPLEX);
	else if (ft_strncmp(str, "--adaptive", ft_strlen("--adaptive") + 1) == 0)
		return (ADAPTIVE);
	return (INVALID_STRATEGY);
}

static int	process_benchmark(char *str, t_input *input, int *benchmark_found)
{
	if (ft_strncmp(str, "--bench", ft_strlen("--bench") + 1) != 0)
		return (0);
	if (*benchmark_found == 1)
		return (0);
	input->benchmark = 1;
	*benchmark_found = 1;
	return (1);
}

static int	process_flag(char *str, t_input *input,
		int *strategy_found, int *benchmark_found)
{
	t_strategy	strategy;

	strategy = get_strategy(str);
	if (strategy == INVALID_STRATEGY)
		return (process_benchmark(str, input, benchmark_found));
	if (*strategy_found == 1)
		return (0);
	input->strategy = strategy;
	*strategy_found = 1;
	return (1);
}

int	parse_flags(int argc, char **argv, t_input *input)
{
	int	i;
	int	strategy_found;
	int	benchmark_found;

	i = 1;
	strategy_found = 0;
	benchmark_found = 0;
	while (i < argc)
	{
		if (has_flag_prefix(argv[i]))
		{
			if (!process_flag(argv[i], input,
					&strategy_found, &benchmark_found))
				return (0);
		}
		i++;
	}
	return (1);
}
