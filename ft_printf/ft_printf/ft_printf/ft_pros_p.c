/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pros_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:48:46 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/27 18:31:45 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_plen(unsigned long long int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void	ft_putaddress(unsigned long long int n, int *len)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (n >= 16)
		ft_putaddress(n / 16, len);
	ft_putchar(hex_base[n % 16], len);
}

void	ft_pros_p(t_flags *s_flags, va_list	*va, int *len)
{
	unsigned long long int	copy_p;
	int						len_p;

	copy_p = va_arg(*va, unsigned long long int);
	len_p = ft_plen(copy_p) + 2;
	if (copy_p == 0)
		s_flags->width--;
	if (s_flags->minus)
	{
		ft_putstr("0x", len, 3);
		ft_putaddress(copy_p, len);
		while ((s_flags->width)-- > len_p)
			ft_putchar(' ', len);
	}
	else
	{
		while ((s_flags->width)-- > len_p)
			ft_putchar(' ', len);
		ft_putstr("0x", len, 3);
		ft_putaddress(copy_p, len);
	}
}
