/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:06:08 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 16:40:48 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

// --- REQUIRED LIBRARIES ---

# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/ft_printf.h"
# include "get_next_line/get_next_line.h"

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

// next: Pointer to the cnode below.
// prev: Pointer to the cnode above.
typedef struct s_cnode
{
	int				value;
	struct s_cnode	*next;
	struct s_cnode	*prev;
}	t_cnode;

// t_stack: Wrapper for the stack tracking the top cnode and current size.
// top: Pointer to the top-most cnode (first element).
// size: Total number of cnodes in this stack.
typedef struct s_stack
{
	t_cnode	*top;
	int		size;
}	t_stack;

void		ft_apply_operations(t_stack *a, t_stack *b);

// --- stack CREATION & INITIALIZATION ---
t_cnode		*ft_create_cnode(int value);
t_stack		*ft_init_stack_from_array(t_array *array);
void		ft_stack_push_cnode(t_stack *stack, t_cnode *new_cnode);

// --- PARSING & VALIDATION ---
t_array		ft_parsing(int size, char **strs);
void		ft_quick_sort(int *tab, int start, int end);

// --- MEMORY & ERROR MANAGEMENT ---
void		*ft_safe_malloc(size_t size);
t_bool		ft_cleanup_memory(t_bool (*error_handler)(void));
t_bool		ft_allocation_staus(void);
t_bool		ft_error_staus(void);
t_bool		ft_ko_staus(void);
t_bool		ft_ok_staus(void);

// --- MANDATORY MOVEMENTS ---
void		ft_pa_silence(t_stack *a, t_stack *b);
void		ft_pb_silence(t_stack *a, t_stack *b);
void		ft_sa_silence(t_stack *a);
void		ft_sb_silence(t_stack *b);
void		ft_ss_silence(t_stack *a, t_stack *b);
void		ft_ra_silence(t_stack *a);
void		ft_rb_silence(t_stack *b);
void		ft_rr_silence(t_stack *a, t_stack *b);
void		ft_rra_silence(t_stack *a);
void		ft_rrb_silence(t_stack *b);
void		ft_rrr_silence(t_stack *a, t_stack *b);

#endif