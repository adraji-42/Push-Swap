/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:24:23 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 10:02:46 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_bool	ft_handle_alloc_error(void)
{
	ft_putstr_fd("Error:\n\tFailed allocation.", 2);
	return (FAILED);
}

t_bool	ft_print_generic_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (FAILED);
}
