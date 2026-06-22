/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:43:14 by adraji            #+#    #+#             */
/*   Updated: 2025/12/14 18:21:12 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_data_utils.h"

static int	ft_print_dispatcher(t_flags *f, va_list args)
{
	int	count;

	count = 0;
	if (f->specifier == 'c')
		count = ft_print_char_fms(va_arg(args, int), *f);
	else if (f->specifier == 's')
		count = ft_print_str_fms(va_arg(args, char *), *f);
	else if (f->specifier == 'd' || f->specifier == 'i')
		count = ft_print_int_fms(va_arg(args, int), *f);
	else if (f->specifier == 'u')
		count = ft_print_unsigned_fms(va_arg(args, unsigned int), *f);
	else if (f->specifier == 'x' || f->specifier == 'X')
		count = ft_print_hex_fms(va_arg(args, unsigned int), *f);
	else if (f->specifier == 'p')
		count = ft_print_ptr_fms(va_arg(args, void *), *f);
	else if (f->specifier == '%')
		count = ft_putchar_len('%', 1);
	return (count);
}

static int	ft_read_fms(const char *fms, int *index, t_flags *f, va_list args)
{
	int		chars_read;
	int		total_printed;

	(*index)++;
	total_printed = 0;
	chars_read = ft_parse_flags(fms + (*index), f, args);
	if (chars_read < 0)
		return (-1);
	if (!f->specifier)
	{
		if (*index > 0)
			total_printed += ft_putchar_len(fms[(*index) - 1], 1);
	}
	else
		total_printed += ft_print_dispatcher(f, args);
	if (total_printed < 0)
		return (-1);
	*index += chars_read;
	return (total_printed);
}

static int	ft_va_end(va_list args)
{
	va_end(args);
	return (-1);
}

int	ft_printf(const char *fms, ...)
{
	t_vars	var;
	va_list	args;
	t_flags	flags;

	if (!fms)
		return (0);
	var.index = 0;
	var.total_printed = 0;
	va_start(args, fms);
	while (fms[var.index])
	{
		if (fms[var.index] != '%')
			var.current_print = ft_putchar_len(fms[var.index++], 1);
		else if (fms[var.index + 1])
			var.current_print = ft_read_fms(fms, &(var.index), &flags, args);
		else
			return (-1);
		if (var.current_print < 0)
			return (ft_va_end(args));
		var.total_printed += var.current_print;
	}
	va_end(args);
	return (var.total_printed);
}
