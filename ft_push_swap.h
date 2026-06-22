/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:49:04 by adraji            #+#    #+#             */
/*   Updated: 2025/12/29 06:47:16 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

// --- REQUIRED LIBRARIES ---

# include <unistd.h>
# include <stdlib.h>
# include "libftprintf/ft_printf.h"

// --- STATUS MACROS ---

# define FAILED 1
# define SUCCESS 0

// t_array: Stores the initial parsed integers before building the stacks.
// values: Pointer to the integer array.
// size: Number of elements in the array.
typedef struct s_array
{
	int	*values;
	int	size;
}	t_array;

// t_node: Doubly linked list node representing an element in the stack.
// value: The actual integer value.
// rank: The relative position of the value if the stack was sorted (0 to N-1).
// pos: The current index of the node in the stack (from top to bottom).
// target_dist: Calculated distance/cost to move this node to a specific target.
// next: Pointer to the node below.
// prev: Pointer to the node above.
typedef struct s_node
{
	int				value;
	int				rank;
	int				pos;
	int				target_dist;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// t_stack: Wrapper for the stack tracking the top node and current size.
// top: Pointer to the top-most node (first element).
// size: Total number of nodes in this stack.
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// --- STACK CREATION & INITIALIZATION ---
t_node	*ft_create_node(int value);
t_stack	*ft_init_stack_from_array(t_array *array);
void	ft_stack_push_node(t_stack *stack, t_node *new_node);

// --- PARSING & VALIDATION ---
t_array	ft_parsing(int size, char **strs);
void	ft_quick_sort(int *tab, int start, int end);

// --- MEMORY & ERROR MANAGEMENT ---
void	*ft_safe_malloc(size_t size);
t_bool	ft_cleanup_memory(t_bool (*error_handler)(void));
t_bool	ft_handle_alloc_error(void);
t_bool	ft_print_generic_error(void);

// --- STACK INFORMATION & CALCULATIONS ---
void	ft_set_stack_indices(t_node *top);
void	ft_set_value_ranks(t_node *top, t_array *array);
void	ft_calculate_node_distances(t_stack *stack);

// --- MANDATORY MOVEMENTS ---
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

// --- SORTING FUNCTION ---

void	ft_sort_prep(t_stack *a, t_stack *b);
void	ft_sorting(t_stack *a, t_stack *b);

#endif