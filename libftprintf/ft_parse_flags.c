/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:58:50 by adraji            #+#    #+#             */
/*   Updated: 2025/12/21 12:18:59 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_data_utils.h"

static int	ft_get_flags(const char *fmt, t_flags *f)
{
	int	i;

	i = 0;
	while (fmt[i] && ft_strchr("-0# +", fmt[i]))
	{
		if (fmt[i] == '-')
			f->minus = TRUE;
		else if (fmt[i] == '0')
			f->zero = TRUE;
		else if (fmt[i] == '#')
			f->hash = TRUE;
		else if (fmt[i] == ' ')
			f->space = TRUE;
		else if (fmt[i] == '+')
			f->plus = TRUE;
		i++;
	}
	if (f->minus)
		f->zero = FALSE;
	if (f->plus)
		f->space = FALSE;
	return (i);
}

static int	ft_get_width(const char *fmt, t_flags *f, va_list args)
{
	int	i;

	i = 0;
	if (fmt[i] == '*')
	{
		f->width = va_arg(args, int);
		i++;
		if (f->width < 0)
		{
			f->minus = TRUE;
			f->width *= -1;
			f->zero = FALSE;
		}
	}
	else
	{
		f->width = ft_ston(fmt + i);
		if (f->width < 0)
			return (-1);
		while (ft_isdigit(fmt[i]))
			i++;
	}
	return (i);
}

static int	ft_get_precision(const char *fmt, t_flags *f, va_list args)
{
	int	i;

	i = 0;
	if (fmt[i] == '.')
	{
		f->dot = TRUE;
		i++;
		if (fmt[i] == '*')
		{
			f->precision = va_arg(args, int);
			i++;
		}
		else
		{
			f->precision = ft_ston(fmt + i);
			while (ft_isdigit(fmt[i]))
				i++;
		}
		if (f->precision < 0)
			f->dot = FALSE;
	}
	return (i);
}

int	ft_parse_flags(const char *fmt, t_flags *f, va_list args)
{
	int	pos;
	int	check;

	pos = 0;
	ft_memset(f, 0, sizeof(t_flags));
	pos += ft_get_flags(fmt + pos, f);
	check = ft_get_width(fmt + pos, f, args);
	if (check < 0)
		return (-1);
	pos += check;
	pos += ft_get_precision(fmt + pos, f, args);
	if (fmt[pos] && ft_strchr("cspdiuxX%", fmt[pos]))
	{
		f->specifier = fmt[pos];
		pos++;
	}
	if (f->dot && ft_strchr("diuxX", f->specifier))
		f->zero = FALSE;
	return (pos);
}
