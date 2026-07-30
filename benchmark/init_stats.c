/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:17:45 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/29 19:11:58 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"
#include "input.h"
#include "algorithm.h"

t_stats	*init_stats(void)
{
	return (ft_calloc(1, sizeof(t_stats)));
}
