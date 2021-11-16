/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:22:54 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/13 16:43:55 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("2147483648", len, 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', len);
	}
	if (n > 9)
		ft_putnbr(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}
