/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:17:45 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/26 14:45:25 by juliopestan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"
#include "printf.h"
#include "input.h"


t_stats	*init_stats(void)
{
	return (ft_calloc(1, sizeof(t_stats)));
}

