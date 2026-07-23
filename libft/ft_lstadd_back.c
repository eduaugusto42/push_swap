/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:57:28 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/07/22 18:54:04 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *lstnew)
{
	t_list	*last;

	if (!lst || !lstnew)
		return ;
	if (!*lst)
	{
		*lst = lstnew;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = lstnew;
}
