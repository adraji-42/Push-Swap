/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_analysis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:27:48 by adraji            #+#    #+#             */
/*   Updated: 2025/12/25 11:41:56 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_calculate_node_distances(t_stack *stack)
{
	t_node	*tmp;
	int		mid;

	if (!stack->top)
		return ;
	mid = stack->size / 2;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->pos <= mid)
			tmp->target_dist = tmp->pos;
		else
			tmp->target_dist = tmp->pos - stack->size;
		tmp = tmp->next;
	}
}
