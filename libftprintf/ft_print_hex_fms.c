/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_fms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:53:36 by adraji            #+#    #+#             */
/*   Updated: 2025/12/14 15:26:28 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_data_utils.h"

static int	ft_hex_len(unsigned int n, t_flags *f)
{
	int				len;

	if (!n && f->dot && !f->precision)
		return (0);
	len = (!n);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static t_lens	ft_calc_hex_lens(unsigned int n, t_flags *f)
{
	t_lens	len;
	int		prefix_len;

	len.len_zeros = 0;
	len.len_padding = 0;
	prefix_len = 0;
	if (n != 0 && f->hash)
		prefix_len = 2;
	len.len_data = ft_hex_len(n, f);
	if (f->dot && f->precision > len.len_data)
		len.len_zeros = f->precision - len.len_data;
	if (f->dot && len.len_data > 0)
		f->zero = 0;
	len.total_content_len = len.len_data + len.len_zeros + prefix_len;
	if (f->width > len.total_content_len)
		len.len_padding = f->width - len.total_content_len;
	return (len);
}

static int	ft_putnbr_hex(unsigned int n, char case_c)
{
	int		save;
	int		count;
	char	*base;

	save = 0;
	count = 0;
	if (case_c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		save = ft_putnbr_hex(n / 16, case_c);
		if (save < 0)
			return (-1);
		count += save;
	}
	save = ft_putchar_len(base[n % 16], 1);
	if (save < 0)
		return (-1);
	count += save;
	return (count);
}

static int	ft_handle_hex_pre_content(unsigned int n, char *p_char, t_flags *f,
		t_levas *leva)
{
	*p_char = ' ';
	if (f->zero && !f->minus)
	{
		*p_char = '0';
		leva->len.len_padding += leva->len.len_zeros;
		leva->len.len_zeros = 0;
	}
	if (!f->minus && *p_char == ' ')
		if (ft_put_padding(' ', &leva->len, &leva->var) < 0)
			return (-1);
	if (n != 0 && f->hash)
	{
		if (f->specifier == 'x')
			leva->var.current_print = write(1, "0x", 2);
		else
			leva->var.current_print = write(1, "0X", 2);
		if (leva->var.current_print < 0)
			return (-1);
		leva->var.total_printed += leva->var.current_print;
	}
	return (1);
}

int	ft_print_hex_fms(unsigned int n, t_flags f)
{
	t_levas	leva;
	char	p_char;

	leva.len = ft_calc_hex_lens(n, &f);
	leva.var.total_printed = 0;
	if (ft_handle_hex_pre_content(n, &p_char, &f, &leva) < 0)
		return (-1);
	if (!f.minus && p_char == '0')
		if (ft_put_padding('0', &leva.len, &leva.var) < 0)
			return (-1);
	if (ft_put_zeros(leva.len.len_zeros, &leva.var) < 0)
		return (-1);
	if (leva.len.len_data > 0)
	{
		leva.var.current_print = ft_putnbr_hex(n, f.specifier);
		if (leva.var.current_print < 0)
			return (-1);
		leva.var.total_printed += leva.var.current_print;
	}
	if (f.minus)
		if (ft_put_padding(' ', &leva.len, &leva.var) < 0)
			return (-1);
	return (leva.var.total_printed);
}
