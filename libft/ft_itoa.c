/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:32:30 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/06/05 11:26:28 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(int	*n);
static int	num_len(int n);

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	sign;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	sign = check_sign(&n);
	len = num_len(n);
	itoa = malloc(sign + len + 1);
	if (!itoa)
		return (NULL);
	itoa[sign + len] = '\0';
	while (n != 0)
	{
		len--;
		itoa[sign + len] = (n % 10) + '0';
		n /= 10;
	}
	if (sign > 0)
		itoa[0] = '-';
	return (itoa);
}

static int	check_sign(int	*n)
{
	int	sign;

	sign = 0;
	if (*n < 0)
	{
		*n *= -1;
		sign++;
	}
	return (sign);
}

static int	num_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
