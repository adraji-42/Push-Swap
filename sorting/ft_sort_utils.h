/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:56:25 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 16:51:12 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_UTILS_H
# define FT_SORT_UTILS_H

# include "../ft_push_swap.h"

typedef struct s_operations
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	cost;
}	t_op;

// Function prototypes for stack manipulation and cost calculation
t_node	*ft_find_min_rank(t_stack *stack);
t_node	*ft_find_max_rank(t_stack *stack);
void	ft_prepare_push_a(t_stack *a, t_stack *b);
t_op	ft_prepare_push_b(t_stack *a, t_stack *b);
void	ft_apply_moves(t_stack *a, t_stack *b, t_op op);

#endif
