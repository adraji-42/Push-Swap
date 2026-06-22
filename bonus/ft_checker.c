/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:05:35 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 15:56:30 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void	ft_checke(t_stack *a, t_stack *b)
{
	t_cnode	*current;

	current = a->top;
	if (b->top)
		exit(ft_cleanup_memory(ft_ko_staus));
	while (current && current->next)
	{
		if (current->value > current->next->value)
			exit(ft_cleanup_memory(ft_ko_staus));
		current = current->next;
	}
	exit(ft_cleanup_memory(ft_ok_staus));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_array	array;

	if (argc < 2)
		return (0);
	array = ft_parsing(argc - 1, &argv[1]);
	a = ft_init_stack_from_array(&array);
	b = ft_init_stack_from_array(NULL);
	free(array.values);
	ft_apply_operations(a, b);
	ft_checke(a, b);
	return (0);
}
