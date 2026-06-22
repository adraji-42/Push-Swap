/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_indexing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:25:30 by adraji            #+#    #+#             */
/*   Updated: 2025/12/25 10:38:00 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_set_stack_indices(t_node *top)
{
	int	i;

	i = 0;
	while (top)
	{
		top->pos = i++;
		top = top->next;
	}
}

void	ft_quick_sort(int *tab, int start, int end)
{
	int	i;
	int	j;
	int	axis;
	int	tmp;

	if (start >= end)
		return ;
	axis = tab[start + (end - start) / 2];
	i = start - 1;
	j = end + 1;
	while (TRUE)
	{
		while (tab[++i] < axis)
			;
		while (tab[--j] > axis)
			;
		if (i >= j)
			break ;
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
	}
	ft_quick_sort(tab, start, j);
	ft_quick_sort(tab, j + 1, end);
}

static int	ft_binary_search(int *tab, int size, int target)
{
	int	low;
	int	mid;
	int	high;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (tab[mid] == target)
			return (mid);
		if (tab[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	exit(ft_cleanup_memory(ft_print_generic_error));
}

void	ft_set_value_ranks(t_node *top, t_array *array)
{
	ft_quick_sort(array->values, 0, array->size - 1);
	while (top)
	{
		top->rank = ft_binary_search(array->values, array->size, top->value);
		top = top->next;
	}
}
