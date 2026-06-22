/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_silence.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 11:59:56 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 13:26:04 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_checker.h"

static void	ft_reverse_rotate_silence(t_stack *stack)
{
	t_cnode	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = stack->top;
	last->prev = NULL;
	stack->top->prev = last;
	stack->top = last;
}

void	ft_rra_silence(t_stack *a)
{
	ft_reverse_rotate_silence(a);
}

void	ft_rrb_silence(t_stack *b)
{
	ft_reverse_rotate_silence(b);
}

void	ft_rrr_silence(t_stack *a, t_stack *b)
{
	ft_reverse_rotate_silence(a);
	ft_reverse_rotate_silence(b);
}
