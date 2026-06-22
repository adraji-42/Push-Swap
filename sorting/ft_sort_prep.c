/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_prep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:38:40 by adraji            #+#    #+#             */
/*   Updated: 2025/12/30 18:44:50 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort_utils.h"

static t_bool	ft_is_rev_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

static void	ft_sort_descending(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		ft_sa(a);
		exit(ft_cleanup_memory(NULL));
	}
	if (a->size == 3)
	{
		ft_sa(a);
		ft_rra(a);
		exit(ft_cleanup_memory(NULL));
	}
	while (a->size > 3)
	{
		ft_rra(a);
		ft_pb(a, b);
	}
	ft_ra(a);
	ft_sa(a);
	while (b->size > 0)
		ft_pa(a, b);
	exit(ft_cleanup_memory(NULL));
}

void	ft_sort_prep(t_stack *a, t_stack *b)
{
	if (ft_is_rev_sorted(a))
		ft_sort_descending(a, b);
	ft_sorting(a, b);
}
