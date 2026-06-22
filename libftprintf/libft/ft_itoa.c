/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:34:54 by adraji            #+#    #+#             */
/*   Updated: 2025/12/15 09:23:57 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizenb(int n)
{
	size_t			size;
	unsigned int	nb;

	size = (n <= 0);
	if (n == 0)
		return (1);
	if (n < 0)
		nb = (unsigned int)-n;
	else
		nb = (unsigned int)n;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*nb;
	unsigned int	nbr;

	len = ft_sizenb(n);
	nb = malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (NULL);
	if (n == 0)
		nb[0] = '0';
	nbr = (unsigned int)n;
	if (n < 0)
		nbr = -nbr;
	nb[len] = '\0';
	while (nbr > 0)
	{
		nb[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		nb[0] = '-';
	return (nb);
}
