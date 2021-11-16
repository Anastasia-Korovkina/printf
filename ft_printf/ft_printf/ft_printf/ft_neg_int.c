/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:46:30 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/13 17:47:23 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_neg_int_sub1(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->precision == -1)
	{
		if (s_flags->zero)
		{
			ft_putchar('-', len);
			while ((s_flags->width)-- > len_num)
				ft_putchar('0', len);
			ft_putnbr(-copy_arg, len);
		}
		else
		{
			while ((s_flags->width)-- > len_num)
				ft_putchar(' ', len);
			if (copy_arg == -2147483648)
				ft_putchar('-', len);
			ft_putnbr(copy_arg, len);
		}
	}
	else
	{
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
		if (copy_arg == -2147483648)
			ft_putchar('-', len);
		ft_putnbr(copy_arg, len);
	}
}

void	ft_neg_int_sub(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->precision >= len_num)
	{
		while ((s_flags->width)-- > s_flags->precision + 1)
			ft_putchar(' ', len);
		ft_putchar('-', len);
		while ((s_flags->precision)-- >= len_num)
			ft_putchar('0', len);
		ft_putnbr(-copy_arg, len);
	}
	else
		ft_neg_int_sub1(s_flags, copy_arg, len, len_num);
}

void	ft_neg_int(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->minus)
	{
		if (s_flags->precision >= len_num)
		{
			ft_putchar('-', len);
			while ((s_flags->precision)-- >= len_num)
				ft_putchar('0', len);
			ft_putnbr(-copy_arg, len);
			while ((s_flags->width)-- > fix_precision + 1)
				ft_putchar(' ', len);
		}
		else
		{
			if (copy_arg == -2147483648)
				ft_putchar('-', len);
			ft_putnbr(copy_arg, len);
			while ((s_flags->width)-- > len_num)
				ft_putchar(' ', len);
		}
	}
	else
		ft_neg_int_sub(s_flags, copy_arg, len, len_num);
}
