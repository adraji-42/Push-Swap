/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 10:44:03 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 15:11:48 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_array	array;

	if (argc < 2)
		return (SUCCESS);
	array = ft_parsing(argc - 1, &argv[1]);
	a = ft_init_stack_from_array(&array);
	b = ft_init_stack_from_array(NULL);
	free(array.values);
	ft_sort_prep(a, b);
	return (0);
}
