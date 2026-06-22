/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_silence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:15:24 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 15:41:57 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_checker.h"

static void	ft_rotate_silence(t_stack *stack)
{
	t_cnode	*first;
	t_cnode	*last;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	stack->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ft_ra_silence(t_stack *a)
{
	ft_rotate_silence(a);
}

void	ft_rb_silence(t_stack *b)
{
	ft_rotate_silence(b);
}

void	ft_rr_silence(t_stack *a, t_stack *b)
{
	ft_rotate_silence(a);
	ft_rotate_silence(b);
}
