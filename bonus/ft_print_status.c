/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:24:23 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 18:27:36 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_bool	ft_allocation_staus(void)
{
	ft_putstr_fd("Error:\n\tFailed allocation.", 2);
	return (FAILED);
}

t_bool	ft_error_staus(void)
{
	ft_putstr_fd("Error\n", 2);
	return (FAILED);
}

t_bool	ft_ko_staus(void)
{
	ft_printf("KO\n");
	return (FAILED);
}

t_bool	ft_ok_staus(void)
{
	ft_printf("OK\n");
	return (SUCCESS);
}
