/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:38:31 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/19 21:38:46 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag_width(char **format, t_flags	*s_flags, va_list	*va)
{
	if (**format == '*')
	{
		s_flags->star1 = 1;
		s_flags->width = va_arg(*va, int);
		if (s_flags->width < 0)
		{
			s_flags->width *= -1;
			s_flags->minus = 1;
		}
		(*format)++;
	}
	else if (**format >= '0' && **format <= '9')
		s_flags->width = ft_atoi(format);
}
