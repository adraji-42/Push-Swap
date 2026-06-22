/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_fms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:45:48 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 18:12:12 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_data_utils.h"

static int	ft_unbr_len(unsigned int n, t_flags *f)
{
	int	len;

	if (!n && f->dot && !f->precision)
		return (0);
	len = 0;
	if (!n)
		len = 1;
	else
	{
		while (n > 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}

static t_lens	ft_calc_unsigned_lens(unsigned int n, t_flags f)
{
	t_lens	len;
	int		sign_len;

	sign_len = 0;
	len.len_zeros = 0;
	len.len_padding = 0;
	len.len_data = ft_unbr_len(n, &f);
	if (f.dot && f.precision > len.len_data)
		len.len_zeros = f.precision - len.len_data;
	if (f.dot && len.len_data > 0)
		f.zero = 0;
	len.total_content_len = len.len_data + len.len_zeros + sign_len;
	if (f.width > len.total_content_len)
		len.len_padding = f.width - len.total_content_len;
	return (len);
}

static int	ft_putnbr_unsigned_abs(unsigned int n)
{
	size_t	nbr;
	int		save;
	int		count;

	nbr = n;
	save = 0;
	count = 0;
	if (nbr >= 10)
	{
		save = ft_putnbr_unsigned_abs(nbr / 10);
		if (save < 0)
			return (-1);
		count += save;
	}
	save = ft_putchar_len((nbr % 10) + '0', 1);
	if (save < 0)
		return (-1);
	count += save;
	return (count);
}

static int	ft_handle_padding_and_zeros(t_flags f, t_lens *len, t_vars *var)
{
	char	pad_char;

	pad_char = ' ';
	if (f.zero && !f.minus)
		pad_char = '0';
	if (!f.minus && pad_char == ' ')
		if (ft_put_padding(' ', len, var) < 0)
			return (-1);
	if (!f.minus && pad_char == '0')
		if (ft_put_padding('0', len, var) < 0)
			return (-1);
	if (ft_put_zeros(len->len_zeros, var) < 0)
		return (-1);
	return (1);
}

int	ft_print_unsigned_fms(unsigned int n, t_flags f)
{
	t_vars	var;
	t_lens	len;

	len = ft_calc_unsigned_lens(n, f);
	var.total_printed = 0;
	if (ft_handle_padding_and_zeros(f, &len, &var) < 0)
		return (-1);
	if (len.len_data > 0)
	{
		var.current_print = ft_putnbr_unsigned_abs(n);
		if (var.current_print < 0)
			return (-1);
		var.total_printed += var.current_print;
	}
	if (f.minus)
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
	return (var.total_printed);
}
