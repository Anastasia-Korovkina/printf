/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:35:29 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/19 23:57:19 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *s_flags)
{
	s_flags->type = 0;
	s_flags->width = 0;
	s_flags->precision = -1;
	s_flags->minus = 0;
	s_flags->space = 0;
	s_flags->plus = 0;
	s_flags->zero = 0;
	s_flags->hash = 0;
	s_flags->star1 = 0;
	s_flags->star2 = 0;
}
