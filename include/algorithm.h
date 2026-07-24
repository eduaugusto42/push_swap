/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-o <jcesar-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:20:30 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/23 17:47:55 by jcesar-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "stack.h"
# include "operations.h"
# include "algorithm.h"
# include "benchmark.h"

void	sort_simple(t_stack *a, t_stack *b, t_stats *stats, int fd);
void	sort_medium(t_stack *a, t_stack *b, t_stats *stats, int fd);
void	sort_complex(t_stack *a, t_stack *b, t_stats *stats, int fd);
void	sort_adaptive(t_stack *a, t_stack *b, t_stats *stats, int fd);

#endif
