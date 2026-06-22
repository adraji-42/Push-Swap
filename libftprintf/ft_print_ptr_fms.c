/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_fms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:01:14 by adraji            #+#    #+#             */
/*   Updated: 2025/12/14 15:26:28 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_data_utils.h"

static int	ft_ptr_len(size_t n)
{
	int		len;

	len = 0;
	if (!n)
		len = 5;
	else
	{
		while (n > 0)
		{
			n /= 16;
			len++;
		}
	}
	return (len);
}

static t_lens	ft_calc_p_lens(size_t n, t_flags f)
{
	t_lens	len;
	int		prefix_len;

	len.len_zeros = 0;
	len.len_padding = 0;
	prefix_len = 2;
	if (!n)
		prefix_len = 0;
	len.len_data = ft_ptr_len(n);
	len.total_content_len = len.len_data + prefix_len;
	if (f.width > len.total_content_len)
		len.len_padding = f.width - len.total_content_len;
	return (len);
}

static int	ft_putnbr_ptr(size_t n)
{
	int		save;
	int		count;
	char	*base;

	save = 0;
	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		save = ft_putnbr_ptr(n / 16);
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

static int	ft_put_ptr(size_t n, t_vars *var)
{
	if (!n)
		var->current_print = write(1, "(nil)", 5);
	else
		var->current_print = ft_putnbr_ptr(n);
	if (var->current_print < 0)
		return (-1);
	var->total_printed += var->current_print;
	return (1);
}

int	ft_print_ptr_fms(void *ptr, t_flags f)
{
	size_t	n;
	t_vars	var;
	t_lens	len;
	char	pad_char;

	n = (size_t)ptr;
	pad_char = ' ';
	len = ft_calc_p_lens(n, f);
	var.total_printed = 0;
	var.current_print = 0;
	if (!f.minus)
		if (ft_put_padding(pad_char, &len, &var) < 0)
			return (-1);
	if (n)
		var.current_print = write(1, "0x", 2);
	if (var.current_print < 0)
		return (-1);
	var.total_printed += var.current_print;
	if (len.len_data > 0)
		if (ft_put_ptr(n, &var) < 0)
			return (-1);
	if (f.minus)
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
	return (var.total_printed);
}
