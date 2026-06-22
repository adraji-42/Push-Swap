/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ilimit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 08:38:14 by adraji            #+#    #+#             */
/*   Updated: 2025/12/26 14:02:42 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

int	ft_atoi_ilimit(const char *nptr)
{
	long		res;
	int			sign;

	res = 0;
	sign = PLUS;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = MINUS;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		if ((sign == PLUS && res > INT_MAX)
			|| (sign == MINUS && - res < INT_MIN))
			exit(ft_cleanup_memory(ft_print_generic_error));
		nptr++;
	}
	return ((int)(res * sign));
}
