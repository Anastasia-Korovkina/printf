/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_int_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:12:49 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/14 19:55:36 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero_int_sub1(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->precision > 0)
	{
		ft_putnbr(copy_arg, len);
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
	}
	else if (s_flags->precision == -1)
	{
		if (s_flags->space)
		{
			ft_putchar(' ', len);
			s_flags->width--;
		}
		ft_putchar('0', len);
		while ((s_flags->width)-- > 1)
			ft_putchar(' ', len);
	}
	else
	{	
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
	}
}

void	ft_zero_int_sub_s(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->precision > len_num)
	{
		if (s_flags->space)
		{
			ft_putchar(' ', len);
			s_flags->width--;
		}
		while ((s_flags->precision)-- > len_num + 1)
			ft_putchar('0', len);
		ft_putnbr(copy_arg, len);
		while ((s_flags->width)-- > fix_precision)
			ft_putchar(' ', len);
	}
	else
		ft_zero_int_sub1(s_flags, copy_arg, len, len_num);
}

void	ft_zero_int_sub3(t_flags *s_flags, int *len, int len_num)
{
	if (s_flags->precision == -1)
	{
		if (s_flags->zero)
		{
			while ((s_flags->width)-- > 1)
				ft_putchar('0', len);
			ft_putchar('0', len);
		}
		else
		{
			while ((s_flags->width)-- > 1)
				ft_putchar(' ', len);
			ft_putchar('0', len);
		}
	}
	else
	{
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
	}
}

void	ft_zero_int_sub2(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->space)
	{
		ft_putchar(' ', len);
		s_flags->width--;
	}
	if (s_flags->precision > len_num)
	{
		while ((s_flags->width)-- > s_flags->precision)
			ft_putchar(' ', len);
		while ((s_flags->precision)-- > len_num + 1)
			ft_putchar('0', len);
		ft_putnbr(copy_arg, len);
	}
	else if (s_flags->precision > 0)
	{
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
		ft_putnbr(copy_arg, len);
	}
	else
		ft_zero_int_sub3(s_flags, len, len_num);
}

void	ft_zero_int_sub(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->minus)
		ft_zero_int_sub_s(s_flags, copy_arg, len, len_num);
	else
		ft_zero_int_sub2(s_flags, copy_arg, len, len_num);
}
