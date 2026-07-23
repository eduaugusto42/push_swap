/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:20:30 by jcesar-o          #+#    #+#             */
/*   Updated: 2026/07/22 21:44:00 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "stack.h"
# include "operations.h"

double	compute_disorder(int *numbers, int size);

void	sort_simple(t_stack *a, t_stack *b, t_stats *stats, int fd);
void	sort_medium(t_stack *a, t_stack *b, t_stats *stats, int fd);
void	sort_complex(t_stack *a, t_stack *b, t_stats *stats, int fd);
void	sort_adaptive(t_stack *a, t_stack *b, t_stats *stats, int fd);

#endif
