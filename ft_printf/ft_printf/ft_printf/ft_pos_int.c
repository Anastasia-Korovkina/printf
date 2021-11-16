/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:20:14 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/24 15:29:23 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_plus_sub(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->precision > len_num)
	{
		while ((s_flags->width)-- >= len_num + s_flags->precision)
			ft_putchar(' ', len);
		ft_putchar('+', len);
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
		ft_putnbr(copy_arg, len);
	}
	else if (s_flags->precision > 0)
	{
		while ((s_flags->width)-- > len_num + 1)
			ft_putchar(' ', len);
		ft_putchar('+', len);
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
		ft_putnbr(copy_arg, len);
	}
	else if (s_flags->precision == -1)
	{
		if (s_flags->space)
			s_flags->width--;
		if (s_flags->zero)
		{
			ft_putchar('+', len);
			while ((s_flags->width)-- > len_num + 1)
				ft_putchar('0', len);
			ft_putnbr(copy_arg, len);
		}
		else
		{
			while ((s_flags->width)-- > len_num + s_flags->precision)
				ft_putchar(' ', len);
			ft_putchar('+', len);
			while ((s_flags->precision)-- > len_num)
				ft_putchar('0', len);
			ft_putnbr(copy_arg, len);
		}
	}
	else
	{
		while ((s_flags->width)-- > len_num + 1)
			ft_putchar(' ', len);
		ft_putchar('+', len);
		ft_putnbr(copy_arg, len);
	}
}

void	ft_flag_plus(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->minus)
	{
		if (s_flags->precision > len_num)
		{
			ft_putchar('+', len);
			while ((s_flags->precision)-- > len_num)
				ft_putchar('0', len);
			ft_putnbr(copy_arg, len);
			while ((s_flags->width)-- > fix_precision + 1)
				ft_putchar(' ', len);
		}
		else
		{
			ft_putchar('+', len);
			ft_putnbr(copy_arg, len);
			while ((s_flags->width)-- > len_num + 1)
				ft_putchar(' ', len);
		}
	}
	else
		ft_flag_plus_sub(s_flags, copy_arg, len, len_num);
}

void	ft_pos_int(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->plus)
		ft_flag_plus(s_flags, copy_arg, len, len_num);
	else
		ft_pos_int_sub(s_flags, copy_arg, len, len_num);
}
