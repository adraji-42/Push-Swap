/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_silence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:11:46 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 13:27:28 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_checker.h"

static void	ft_swap_silence(t_stack *stack)
{
	t_cnode	*first;
	t_cnode	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	stack->top = second;
}

void	ft_sa_silence(t_stack *a)
{
	ft_swap_silence(a);
}

void	ft_sb_silence(t_stack *b)
{
	ft_swap_silence(b);
}

void	ft_ss_silence(t_stack *a, t_stack *b)
{
	ft_swap_silence(a);
	ft_swap_silence(b);
}
