/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_fms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:15:24 by adraji            #+#    #+#             */
/*   Updated: 2025/12/14 15:26:28 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_data_utils.h"

static int	ft_nbr_len_int(int n, t_flags *f)
{
	int	len;

	if (!n && f->dot && !f->precision)
		return (0);
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = -n;
	len = (!n);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static t_lens	ft_calc_int_lens(int n, t_flags f)
{
	t_lens	len;
	int		sign_len;

	len.len_zeros = 0;
	len.len_padding = 0;
	sign_len = 0;
	if (n < 0 || f.plus || f.space)
		sign_len = 1;
	len.len_data = ft_nbr_len_int(n, &f);
	if (f.dot && f.precision > len.len_data)
		len.len_zeros = f.precision - len.len_data;
	if (f.dot && len.len_data > 0)
		f.zero = 0;
	len.total_content_len = len.len_data + len.len_zeros + sign_len;
	if (f.width > len.total_content_len)
		len.len_padding = f.width - len.total_content_len;
	return (len);
}

static int	ft_put_sign(int n, t_flags *f)
{
	if (n < 0)
		return (ft_putchar_len('-', 1));
	else if (f->plus)
		return (ft_putchar_len('+', 1));
	else if (f->space)
		return (ft_putchar_len(' ', 1));
	return (0);
}

static int	ft_put_int_prefix_and_padding(
	int n, t_flags f, t_lens *len, t_vars *var)
{
	char	pad_char;

	pad_char = ' ';
	if (f.zero && !f.minus)
		pad_char = '0';
	if (!f.minus && pad_char == ' ')
	{
		if (ft_put_padding(' ', len, var) < 0)
			return (-1);
	}
	var->current_print = ft_put_sign(n, &f);
	if (var->current_print < 0)
		return (-1);
	var->total_printed += var->current_print;
	if (!f.minus && pad_char == '0')
	{
		if (ft_put_padding('0', len, var) < 0)
			return (-1);
	}
	if (ft_put_zeros(len->len_zeros, var) < 0)
		return (-1);
	return (1);
}

int	ft_print_int_fms(int n, t_flags f)
{
	t_vars	var;
	t_lens	len;

	len = ft_calc_int_lens(n, f);
	var.total_printed = 0;
	if (ft_put_int_prefix_and_padding(n, f, &len, &var) < 0)
		return (-1);
	if (len.len_data > 0)
	{
		var.current_print = ft_putnbr_abs(n);
		if (var.current_print < 0)
			return (-1);
		var.total_printed += var.current_print;
	}
	if (f.minus)
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
	return (var.total_printed);
}
