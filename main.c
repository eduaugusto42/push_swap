/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:32:07 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/10 19:17:15 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	is_valid_number(char *token)
{
	int	i;
	
	i = 0;
	if (!token || token[i] == '\0')
		return (0);
	if (token[i] == '-' || token[i] == '+')
		i++;
	if (token[i] == '\0')
		return (0);
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	**tokens;
	

	i = 1;
	while (i < argc)
	{
		j = 0;
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (error);
		while (tokens[j])
			j++;
		i++;
	}
	
}
