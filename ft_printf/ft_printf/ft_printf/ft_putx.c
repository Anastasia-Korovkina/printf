/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:19:17 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/13 14:37:34 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putx(unsigned int n, int *len, char *hex_base)
{
	if (n >= 16)
		ft_putx(n / 16, len, hex_base);
	ft_putchar(hex_base[n % 16], len);
}
