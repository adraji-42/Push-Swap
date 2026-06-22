/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 08:38:14 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 14:36:16 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

void	ft_quick_sort(int *tab, int start, int end)
{
	int	i;
	int	j;
	int	axis;
	int	tmp;

	if (start >= end)
		return ;
	axis = tab[start + (end - start) / 2];
	i = start - 1;
	j = end + 1;
	while (TRUE)
	{
		while (tab[++i] < axis)
			;
		while (tab[--j] > axis)
			;
		if (i >= j)
			break ;
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
	}
	ft_quick_sort(tab, start, j);
	ft_quick_sort(tab, j + 1, end);
}

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
			exit(ft_cleanup_memory(ft_error_staus));
		nptr++;
	}
	return ((int)(res * sign));
}
