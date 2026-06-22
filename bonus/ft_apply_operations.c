/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:39:28 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 18:27:59 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void	execute_operation(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(op, "pa\n", 3))
		ft_pa_silence(a, b);
	else if (!ft_strncmp(op, "pb\n", 3))
		ft_pb_silence(a, b);
	else if (!ft_strncmp(op, "sa\n", 3))
		ft_sa_silence(a);
	else if (!ft_strncmp(op, "sb\n", 3))
		ft_sb_silence(b);
	else if (!ft_strncmp(op, "ss\n", 3))
		ft_ss_silence(a, b);
	else if (!ft_strncmp(op, "ra\n", 3))
		ft_ra_silence(a);
	else if (!ft_strncmp(op, "rb\n", 3))
		ft_rb_silence(b);
	else if (!ft_strncmp(op, "rr\n", 3))
		ft_rr_silence(a, b);
	else if (!ft_strncmp(op, "rra\n", 4))
		ft_rra_silence(a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		ft_rrb_silence(b);
	else if (!ft_strncmp(op, "rrr\n", 4))
		ft_rrr_silence(a, b);
	else
		exit(ft_cleanup_memory(ft_error_staus));
}

void	ft_apply_operations(t_stack *a, t_stack *b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		execute_operation(operation, a, b);
		free(operation);
		operation = get_next_line(0);
	}
}
