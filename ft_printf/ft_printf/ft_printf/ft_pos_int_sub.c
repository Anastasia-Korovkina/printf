/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_int_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:17:09 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/27 17:27:28 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pos_int_sub3(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->zero)
	{
		if (s_flags->space)
		{
			ft_putchar(' ', len);
			len_num++;
		}
		while ((s_flags->width)-- > len_num)
			ft_putchar('0', len);
		ft_putnbr(copy_arg, len);
	}
	else
	{
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
		ft_putnbr(copy_arg, len);
	}
}

void	ft_pos_int_sub2(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->precision > len_num)
	{
		if (s_flags->space && (s_flags->width <= s_flags->precision))
			ft_putchar(' ', len);
		while ((s_flags->width)-- > s_flags->precision)
			ft_putchar(' ', len);
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
		ft_putnbr(copy_arg, len);
	}
	else if (s_flags->precision == -1)
	{
		if (s_flags->space)
			ft_putchar(' ', len);
		ft_pos_int_sub3(s_flags, copy_arg, len, len_num);
	}
	else
	{
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
		ft_putnbr(copy_arg, len);
	}
}

void	ft_pos_int_sub4(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->space)
	{
		ft_putchar(' ', len);
		len_num++;
	}
	ft_putnbr(copy_arg, len);
	while ((s_flags->width)-- > len_num)
		ft_putchar(' ', len);
}

void	ft_pos_int_sub1(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->precision > len_num)
	{
		if (s_flags->space)
		{
			ft_putchar(' ', len);
			fix_precision++;
		}
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
		ft_putnbr(copy_arg, len);
		while ((s_flags->width)-- > fix_precision)
			ft_putchar(' ', len);
	}
	else
		ft_pos_int_sub4(s_flags, copy_arg, len, len_num);
}

void	ft_pos_int_sub(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->minus )
		ft_pos_int_sub1(s_flags, copy_arg, len, len_num);
	else
		ft_pos_int_sub2(s_flags, copy_arg, len, len_num);
}
