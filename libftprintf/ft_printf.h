/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:44 by adraji            #+#    #+#             */
/*   Updated: 2025/12/26 14:02:15 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// --- INTERNAL LIBRARIES AND DEPENDENCIES ---

# include "libft/libft.h"

// --- MACROS AND CONSTANTS ---

# define TRUE 1
# define FALSE 0

//  Ensures INT_MAX is defined for limit checking.
# ifndef INT_MAX
#  define INT_MAX __INT_MAX__
# endif

// --- STRUCTURES FOR PRINTF LOGIC ---

//  Structure to manage length calculations: data, padding, and zeros.
typedef struct s_lens_print_data
{
	int	len_data;
	int	len_zeros;
	int	len_padding;
	int	total_content_len;
}	t_lens;

//  Structure to track indices and total printed characters.
typedef struct s_print_count
{
	int	index;
	int	current_print;
	int	total_printed;
}	t_vars;

//  Wrapper structure to satisfy Norminette line limits in functions.
typedef struct s_norminette
{
	t_lens	len;
	t_vars	var;
}	t_levas;

//  Structure to store formatting flags, width, and precision.
typedef struct s_flags
{
	t_bool	minus;
	t_bool	zero;
	t_bool	dot;
	t_bool	hash;
	t_bool	plus;
	t_bool	space;
	long	width;
	long	precision;
	char	specifier;
}	t_flags;

// --- MAIN PRINTF FUNCTION ---

int	ft_printf(const char *fms, ...);

#endif