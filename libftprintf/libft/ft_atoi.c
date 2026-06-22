/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:01:13 by adraji            #+#    #+#             */
/*   Updated: 2025/12/20 09:50:13 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	n;
	t_signe	signe;

	n = 0;
	signe = PLUS;
	while (*nptr && ((*nptr == ' ') || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = MINUS;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		if (n > LM / 10 || (n == LM / 10 && (*nptr - '0') > LM % 10))
		{
			if (signe == PLUS)
				return (-1);
			return (0);
		}
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(n * signe));
}
