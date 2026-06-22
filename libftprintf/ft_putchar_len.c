/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:51 by adraji            #+#    #+#             */
/*   Updated: 2025/12/14 11:27:10 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_data_utils.h"

int	ft_putchar_len(char c, int n)
{
	int	i;
	int	count;
	int	old_count;

	i = 0;
	count = 0;
	while (i < n)
	{
		old_count = count;
		count += write (1, &c, 1);
		if (count < old_count)
			return (-1);
		i++;
	}
	return (count);
}
