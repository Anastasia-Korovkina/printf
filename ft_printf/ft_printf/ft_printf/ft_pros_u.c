/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pros_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:45:43 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/13 14:16:41 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pros_u_sub4(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->precision == -1)
	{
		if (copy_arg == 0)
			s_flags->width--;
		if (s_flags->zero)
			while ((s_flags->width)-- > fix_precision + len_num + 1)
				ft_putchar('0', len);
		else
			while ((s_flags->width)-- > fix_precision + len_num + 1)
				ft_putchar(' ', len);
		ft_putnbr_u(copy_arg, len);
	}
	else
	{
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
		if (copy_arg != 0)
			ft_putnbr_u(copy_arg, len);
	}
}

void	ft_pros_u_sub2(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->precision > len_num)
	{
		while ((s_flags->width)-- > fix_precision)
			ft_putchar(' ', len);
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
		if (copy_arg != 0)
			ft_putnbr_u(copy_arg, len);
	}
	else
		ft_pros_u_sub4(s_flags, copy_arg, len, len_num);
}

void	ft_pros_u_sub3(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	if (s_flags->precision == -1)
	{
		ft_putnbr_u(copy_arg, len);
		if (copy_arg == 0)
			s_flags->width--;
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
	}
	else
	{
		if (copy_arg != 0)
			ft_putnbr_u(copy_arg, len);
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
	}
}

void	ft_pros_u_sub1(t_flags *s_flags, int copy_arg, int *len, int len_num)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->precision > len_num)
	{
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
		if (copy_arg != 0)
			ft_putnbr_u(copy_arg, len);
		while ((s_flags->width)-- > fix_precision)
			ft_putchar(' ', len);
	}
	else if (s_flags->precision == 0)
	{
		if (copy_arg != 0)
		{
			ft_putnbr_u(copy_arg, len);
			s_flags->width--;
			fix_precision--;
		}
		while ((s_flags->width)-- > fix_precision + len_num)
			ft_putchar(' ', len);
	}
	else
		ft_pros_u_sub3(s_flags, copy_arg, len, len_num);
}

void	ft_pros_u(t_flags *s_flags, va_list	*va, int *len)
{
	unsigned int	copy_arg;
	int				len_num;

	copy_arg = va_arg(*va, unsigned int);
	len_num = ft_ulen(copy_arg);
	if (s_flags->minus)
		ft_pros_u_sub1(s_flags, copy_arg, len, len_num);
	else
		ft_pros_u_sub2(s_flags, copy_arg, len, len_num);
}
