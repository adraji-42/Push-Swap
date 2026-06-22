/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_silence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 08:09:03 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 15:49:25 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_checker.h"

static void	ft_push_silence(t_stack *src, t_stack *dest)
{
	t_cnode	*node_to_push;

	if (!src || !src->top)
		return ;
	node_to_push = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	node_to_push->next = dest->top;
	if (dest->top)
		dest->top->prev = node_to_push;
	dest->top = node_to_push;
	dest->top->prev = NULL;
	src->size--;
	dest->size++;
}

void	ft_pa_silence(t_stack *a, t_stack *b)
{
	ft_push_silence(b, a);
}

void	ft_pb_silence(t_stack *a, t_stack *b)
{
	ft_push_silence(a, b);
}
