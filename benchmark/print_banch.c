/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_banch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 20:00:46 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/20 20:01:46 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "input.h"
#include "benchmark.h"

const char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	if (strategy == MEDIUM)
		return ("Medium");
	if (strategy == COMPLEX)
		return ("Complex");
	if (strategy == ADAPTIVE)
		return ("Adaptive");
	return ("Unknown");
}

const char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("O(n²)");
	if (strategy == MEDIUM)
		return ("O(n log n)");
	if (strategy == COMPLEX)
		return ("O(n log n)");
	if (strategy == ADAPTIVE)
		return ("Adaptive");
	return ("Unknown");
}