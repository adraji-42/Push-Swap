/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_data_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:30:37 by adraji            #+#    #+#             */
/*   Updated: 2025/12/24 13:21:22 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DATA_UTILS_H
# define FT_PRINTF_DATA_UTILS_H

// --- REQUIRED LIBRARIES ---

# include <stdarg.h>
# include "ft_printf.h"

// --- UTILITY FUNCTIONS FOR DATA HANDLING ---

int	ft_ston(const char *nptr);
int	ft_putchar_len(char c, int len);
int	ft_put_padding(char pad_char, t_lens *len, t_vars *var);
int	ft_put_zeros(int len_zeros, t_vars *var);
int	ft_putnbr_abs(int n);

// --- PARSING AND FORMATTING FUNCTIONS ---

int	ft_parse_flags(const char *fmt, t_flags *f, va_list args);
int	ft_print_int_fms(int n, t_flags f);
int	ft_print_char_fms(int c, t_flags f);
int	ft_print_ptr_fms(void *ptr, t_flags f);
int	ft_print_str_fms(const char *s, t_flags f);
int	ft_print_hex_fms(unsigned int n, t_flags f);
int	ft_print_unsigned_fms(unsigned int n, t_flags f);
int	ft_print_percent_fms(t_flags f);

#endif